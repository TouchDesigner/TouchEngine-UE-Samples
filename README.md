# UE TouchEngine Plugin Samples Repository

**Current Unreal Engine version:** `4.26.2`

**Current TouchEngine version:** `2021.12380`

The TouchEngine Plugin currently supports Custom Parameters, CHOP input/output, TOP input/output and DAT input/output.

## Getting started

The TouchEngine plugin is referenced using a git submodule, clone using 

`git clone --recurse gitURL`

When pulling updates, don't forget to do git submodule update to get the latest TouchEngine Plugin version.

`git submodule update`

### Build plugin from repository and submodules

*Scroll down to the next section if you want to use prebuilt binaries.*

On your first use of the project, or if you just pulled changes from the repository, you might be required  to recompile the plugin binaries for your own hardware.

#### Using batch script

You can execute a .bat file with the following script
```
call "[UE4 Install Location]\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin=[Example Project Install Location]\Plugins\TouchEngine-UE4\TouchEngine.uplugin -Package=[Build Destination Location]\TouchEnigne-UE4 -Rocket
```

#### Using Visual Studio

Follow the steps below to build from Visual Studio:

1. Right click `TouchEngineUE4Samp.uproject`
2. Select Generate `Visual Studio project files` ![Generate VS project files](ReadmePictures/ueSamples01.png?raw=true "Generate VS project files")
3. Launch the Visual Studio Solution `TouchEngineUE4Samp.sln` in Visual Studio 2019
4. In Visual Studio, right click the solution and click on `Rebuild solution` ![Rebuild solution](ReadmePictures/ueSamples02.png?raw=true "Rebuild solution")
5. It could take a few minutes. Grab a cup of coffee.
6. Launch `TouchEngineUE4Samp.uproject` in Unreal Engine 4.26.2+

### Use release version

1. Go to the [release page](https://github.com/mbechard/TouchEngine-UE4/releases) and download the latest release zip file.
2. Unzip the downloaded file in `Plugins/`.
3. A folder named TouchEngine-UE4 should now be here with the following structure. ![Plugin folder structure](ReadmePictures/ueSamples03.png?raw=true "Plugin folder structure")
4. Launch `TouchEngineUE4Samp.uproject` in Unreal Engine 4.26.2+

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

This seems to be an install bug, we encountered it on our end as well. With luck, the Epic Games Launcher will shop up with a message mentioning to "Fix the project files", clicking "Fix now" should solve the issue. If the message doesn't show up, another solution is to open your project using right click -> Open with... and open the project with the `UnrealVersionSelector.exe` located in your Epic Games Launcher install folder (by default, `C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64`)

### I am getting an error mentioning map/lighting, what should I do ?

Rebuild the map/lighting to fix the error that comes up when loading the project.

### The examples seem to load forever, what should I do ?

It can take about 5 seconds (subject to change based on hardware) for the subprocess to boot and TouchEngine to load the .tox within Unreal Engine.

## Known issues

TouchEngine only works with DX11 renderer so far. Although DX12 is partially implemented as well.

## Current limitations

TO BE COMPLETED

## TouchEngine Plugin documentation

This repository is covering the sample project and examples, for a complete documentation of the TouchEngine, follow [this link](https://github.com/mbechard/TouchEngine-UE4/).
