![Alt text](docs/public/banner_v2.png?raw=true)

# things to do 
not sure whether to keep WinAPI or just substitute it with open source and cross-platform libraries to be honest.

**possible fuckup with keycodes at `yds_unix_key_maps.cpp`**

anyway
- [ ] audio library (with SDL_audio, not OpenAL if possible)
- [ ] Vulkan support!!!
- [x] create `ysUnixWindowSystem` class (like `ysWindowsWindowSystem`)
- [x] create `ysUnixWindow` class (like `ysWindowsWindow`)
- [x] create `ysUnixMonitor` class (uhhhhhhhhhhhhhh)
- [ ] create input system for linux 
- [ ] a way to provide `GameEngineSetting` struct with used Platform
- [x] implementation of `SurveyMonitors()` in `ysUnixWindowSystem`
## Building the Code

As this codebase is currently not ready for release, I can't make any guarantees about whether it will build for you. However, the process is pretty straightforward for anyone who wants to try:

1. Install Python 3 (if you don't have it already)
2. Clone the *Delta Studio* repository
3. Open ```project/delta-studio.sln``` in Microsoft Visual Studio 2019
4. Build the solution
5. Run the ```delta-basic-demo``` project

That should be all! Assuming your computer has OpenGL 4 or DirectX11 support, the game window should open immediately.

**You are now ready to begin development!**
