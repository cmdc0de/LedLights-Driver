
#include <cmath>
#include <iostream>

int main() {
    float r = 28.735;
    float s = (2*3.14*r)/24;
    float angle = s/r;
    float currentAngle = 0;
    float px,py;
    for(int i=0;i<24;i++) {
        px = r*cos(currentAngle)+34.315;
        py = r*sin(currentAngle)+66.007;
        std::cout << px << "     " << py << std::endl;
        currentAngle = currentAngle + angle;
    }
}