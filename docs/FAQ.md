# FAQ

If errors occur the Message Log window should pop up automatically. However if it does not then you can manually open it via Windows->Developer Tools->Message Log.

## The Unreal related options are missing from the context menu when right clicking the Unreal project file, what should I do ?

This seems to be an install bug, we encountered it on our end as well. With luck, the Epic Games Launcher will show up with a message mentioning to "Fix the project files", clicking "Fix now" should solve the issue. If the message doesn't show up, another solution is to open your project using right click -> Open with... and open the project with the `UnrealVersionSelector.exe` located in your Epic Games Launcher install folder (by default, `C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64`)

## I am getting an error mentioning map/lighting, what should I do ?

Rebuild the map/lighting to fix the error that comes up when loading the project.

## The examples seem to load forever, what should I do ?

It can take about 5-10 seconds (subject to change based on hardware) for the subprocess to boot and TouchEngine to load the .tox within Unreal Engine.

## I just pulled the git repository and got some updates, my project is now starting with a lot of errors, what should I do ?

If you had compiled the plugin manually, chances are that it is now using an older version of the plugin while they are potentially new features in the Unreal Engine project. You can either grab the latest plugin version on our release page in the plugin repository, or re-compile manually the plugin.

If you don't use Visual Studio, delete the binaries from `Plugins\TouchEngine\Binaries\Win64` and Unreal Engine should re-compile the plugin for you at startup.

## I see multiple TouchEngine.exe processes in my task manager while nothing is running, what should I do ?

When Unreal is started and the TouchEngine plugin is loaded, it is normal to occasionally see instances of TouchEngine appear in your task manager even if you didn't hit Play in your Unreal Engine project. If a crash occurs, it can happen that some TouchEngine processes are still running, in which case you should terminate them.

## I can't run the project, it doesn't want to build, what should I do ?

Remember that you are now working in a game engine and that they are prerequisites to game development being applied. In most cases, you will need all the tools required for an Unreal project to compile, with specific versions. 

Unreal usually points which version and which tool you are missing. Those should includes (and are not limited to): Visual Studio Build Tools 2022, .Net Framework, .Net Core Runtime... etc. 

The most common one that users might be missing are the Visual Studio Build Tools, available here: https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022

## I package a project making use of the TouchEngine Plugin but none of my .tox assets come with it.

You need to add the tox files folder to the "Additional Non-Asset Directories" the project settings. The sample project has it added already.

![Additional Non-Asset Directories To Copy](assets/additional_non_assets_dir.png?raw=true "Additional Non-Asset Directories To Copy")
