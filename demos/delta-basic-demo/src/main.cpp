#include "../include/demo_list.h"

#if defined(_MSC_VER)
    #include <Windows.h>

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow)
{
    (void)nCmdShow;
    (void)lpCmdLine;
    (void)hPrevInstance;

    auto api = ysContextObject::DeviceAPI::DirectX11;
    auto demo = delta_demo::DemoApplication::Demo::DeltaBasicDemo;

    delta_demo::DemoApplication *app = delta_demo::CreateApplication(demo);
    app->Initialize((void *)&hInstance, api); 
    app->Run();
    app->Destroy();

    return 0;
}
#else
    #include <SDL2/SDL.h>

    int main (int argc, char *argv[]) {
        auto api = ysContextObject::DeviceAPI::OpenGL4_0;
        auto demo = delta_demo::DemoApplication::Demo::DeltaBasicDemo;
        auto* app = delta_demo::CreateApplication(demo);

        app->Initialize(nullptr, api);
        app->Run();
        app->Destroy();

        return 0;
    }
    
#endif
