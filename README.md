# TouchEngine For UE Plugin Samples Repository

**Current Unreal Engine version:** `5.0.3`

The TouchEngine Plugin currently supports Custom Parameters, CHOP input/output, TOP input/output and DAT input/output.

## Getting started

The TouchEngine plugin is referenced using a git submodule, clone using 

`git clone --branch UE5.0-Release --recurse https://github.com/TouchDesigner/TouchEngine-UE-Samples.git`

Where `UE5.0-Release` can be replaced by a branch you wish to clone and checkout, if different than the main release branch.

Where `https://github.com/TouchDesigner/TouchEngine-UE-Samples.git` can be replaced by the SSH URL.

When pulling updates, don't forget to do a submodule update to get the latest TouchEngine For UE Plugin version using

`git submodule update`

### Build plugin from repository and submodules

*Scroll down to the next section if you want to use prebuilt binaries.*

On your first use of the project, or if you just pulled changes from the repository, you might be required  to recompile the plugin binaries for your own hardware.

There is two ways you can get started compiling the latest source files, using a **batch script** OR using **Visual Studio**:

#### Using batch script

You can execute a .bat file with the following script
```
call "[UE Install Location]\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin=[Example Project Install Location]\Plugins\TouchEngine\TouchEngine.uplugin -Package=[Build Destination Location]\TouchEnigne-UE -Rocket
```

Where

- `UE Install Location` is the root folder of your Unreal Engine installation. It should be similar to `C:/Program Files/Epic Games/UE_5.0/` if you are using default locations.
- `Example Project Install Location` is the path to the local copy of this repository on your computer.
- `Build Destination Location` is the path to the folder where the compiled binaries will be moved.

#### Using Visual Studio

Follow the steps below to build from Visual Studio:

1. Right click `TouchEngineUESamp.uproject`
2. Select Generate `Visual Studio project files` ![Generate VS project files](ReadmePictures/ueSamples01.png?raw=true "Generate VS project files")
3. Launch the Visual Studio Solution `TouchEngineUESamp.sln` in Visual Studio 2022
4. In Visual Studio, right click the project `TouchEngineUESamp` and `Set as startup project`, it should appear in **Bold**.
![Set startup project](ReadmePictures/ueSamples_startup.png?raw=true "Set startup project")
5. At the top of Visual Studio, you should see two drop down menus, set the configuration to `Development Editor` and the target platform to be `Win64`.
![Set configuration](ReadmePictures/ueSamples_configuration.png?raw=true "Set configuration")
6. In Visual Studio, right click the solution and click on `Rebuild solution`.
![Rebuild solution](ReadmePictures/ueSamples02.png?raw=true "Rebuild solution")
7. It could take a few minutes. Grab a cup of coffee.
8. Launch `TouchEngineUESamp.uproject` in Unreal Engine 5.0.3+

### Use release version

After cloning or downloading the archive of this repository, unzip and go to its root.

1. Go to the [release page](https://github.com/TouchDesigner/TouchEngine-UE/releases) and download the latest release zip file.
2. In the TouchEngine-UE Samples folder, unzip the downloaded file in `Plugins/`.
3. A folder named TouchEngine should now be here with a structure similar to the one in the following screenshot. ![Plugin folder structure](ReadmePictures/ueSamples03.png?raw=true "Plugin folder structure")
4. Launch `TouchEngineUESamp.uproject` in Unreal Engine 5.0.3+

## Examples

Open the Level Blueprint to see the network of operations used to run TouchEngine.

For a detailed walkthrough of the examples, [go here](Content/README.md).

## Using a specific build of TouchEngine

By default, the TouchEngine build used by the Unreal Plugin will be from the most recently installed TouchDesigner on the system.

To override and use a specific build, the Unreal Plugin looks for a shortcut named “TouchEngine” when loading. 

If you place any of the following, named "TouchEngine", alongside the .tox you're opening, it will use that build

- a Windows .lnk to a TouchDesigner installation
- a symlink to a TouchDesigner installation
- a full TouchDesigner installation

## Troubleshooting

If errors occur the Message Log window should pop up automatically. However if it does not then you can manually open it via Windows->Developer Tools->Message Log.

### The Unreal related options are missing from the context menu when right clicking the Unreal project file, what should I do ?

This seems to be an install bug, we encountered it on our end as well. With luck, the Epic Games Launcher will show up with a message mentioning to "Fix the project files", clicking "Fix now" should solve the issue. If the message doesn't show up, another solution is to open your project using right click -> Open with... and open the project with the `UnrealVersionSelector.exe` located in your Epic Games Launcher install folder (by default, `C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64`)

### I am getting an error mentioning map/lighting, what should I do ?

Rebuild the map/lighting to fix the error that comes up when loading the project.

### The examples seem to load forever, what should I do ?

It can take about 5-10 seconds (subject to change based on hardware) for the subprocess to boot and TouchEngine to load the .tox within Unreal Engine.

### I just pulled the git repository and got some updates, my project is now starting with a lot of errors, what should I do ?

If you had compiled the plugin manually, chances are that it is now using an older version of the plugin while they are potentially new features in the Unreal Engine project. You can either grab the latest plugin version on our release page in the plugin repository, or re-compile manually the plugin.

If you don't use Visual Studio, delete the binaries from `Plugins\TouchEngine\Binaries\Win64` and Unreal Engine should re-compile the plugin for you at startup.

### I see multiple TouchEngine.exe processes in my task manager while nothing is running, what should I do ?

When Unreal is started and the TouchEngine plugin is loaded, it is normal to occasionally see instances of TouchEngine appear in your task manager even if you didn't hit Play in your Unreal Engine project. If a crash occurs, it can happen that some TouchEngine processes are still running, in which case you should terminate them.

### I can't run the project, it doesn't want to build, what should I do ?

Remember that you are now working in a game engine and that they are prerequisites to game development being applied. In most cases, you will need all the tools required for an Unreal project to compile, with specific versions. 

Unreal usually points which version and which tool you are missing. Those should includes (and are not limited to): Visual Studio Build Tools 2022, .Net Framework, .Net Core Runtime... etc. 

The most common one that users might be missing are the Visual Studio Build Tools, available here: https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022


## Known issues and current limitations

See release page for known issues on latest releases.

## TouchEngine For UE Plugin documentation

This repository is covering the sample project and examples, for a complete documentation of the TouchEngine For UE Plugin, follow [this link](https://github.com/TouchDesigner/TouchEngine-UE/).
