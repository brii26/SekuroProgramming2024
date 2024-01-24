#include "pbPlots/pbPlots.hpp"
#include "pbPlots/supportLib.hpp"
#include "swerve.hpp"

int main()
{
    Swerve swerveRobot;
    swerveRobot.calculateVelocities();
    swerveRobot.updatePose(0.01);
    
    const std::vector<double>& x = swerveRobot.getX();
    const std::vector<double>& y = swerveRobot.getY();

    RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();

    DrawScatterPlot(imageReference, 600, 400, &x, &y);

    std::vector<double> *pngdata;
    ConvertToPNG(imageReference->image);
    WriteToFile(pngdata, "grafik_y_terhadap_x.png");


    DeleteImage(imageReference->image);

    return 0;
    //ini can't compile, aku ga ngerti cara masukin data vector buat dijadiin grafik ,jadi yasudalah
}
