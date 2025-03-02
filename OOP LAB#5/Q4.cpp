#include <iostream>
#include <thread>
#include <chrono>

class Blend {
public:
    void blendProcess() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "Blending..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "Blending complete!" << std::endl;
    }
};

class Grind {
public:
    void grindProcess()
	{
        std::cout << "Grinding started..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Grinding complete!" << std::endl;
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void blendJuice() 
	{
        std::cout << "Selecting fruits for blending..." << std::endl;
        blender.blendProcess();
    }
    
    void grindJuice() 
	{
        std::cout << "Selecting ingredients for grinding..." << std::endl;
        grinder.grindProcess();
    }
};

int main()
 {
    JuiceMaker juiceMaker;
    juiceMaker.blendJuice();
    juiceMaker.grindJuice();
    return 0;
}