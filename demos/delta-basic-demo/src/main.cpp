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

        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            fprintf(stderr, "SDL Could not initialize.\n%s\n", SDL_GetError());
            return -1;
        }

        auto api = ysContextObject::DeviceAPI::OpenGL4_0;
        auto demo = delta_demo::DemoApplication::Demo::DeltaBasicDemo;

        SDL_Window* window = SDL_CreateWindow(
            "DeltaBasicDemo",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
        );

        if (window == NULL) {
            fprintf(stderr, "Could not create window.\n%s\n", SDL_GetError());
            return -2;
        }

        SDL_Surface* surface = SDL_GetWindowSurface(window);

        auto* app = delta_demo::CreateApplication(demo);
        app->Initialize(window, api);
        app->Run();
        app->Destroy();

        // cleanup
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 0;
    }
    
#endif
