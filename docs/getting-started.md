## Getting started

The TouchEngine plugin is referenced using a git submodule, clone using 

`git clone --branch UE5.2-Release --recurse https://github.com/TouchDesigner/TouchEngine-UE-Samples.git`

Where `UE5.2-Release` can be replaced by a branch you wish to clone and checkout, if different than the main release branch.

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
call "[UE Install Location]\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin=[Example Project Install Location]\Plugins\TouchEngine\TouchEngine.uplugin -Package=[Build Destination Location]\TouchEnigne -Rocket
```

Where

- `UE Install Location` is the root folder of your Unreal Engine installation. It should be similar to `C:/Program Files/Epic Games/UE_5.2/` if you are using default locations.
- `Example Project Install Location` is the path to the local copy of this repository on your computer.
- `Build Destination Location` is the path to the folder where the compiled binaries will be moved.

#### Using Visual Studio

Follow the steps below to build from Visual Studio:

1. Right click `TouchEngineUESamp.uproject`
2. Select Generate `Visual Studio project files` ![Generate VS project files](assets/ueSamples01.png?raw=true "Generate VS project files")
3. Launch the Visual Studio Solution `TouchEngineUESamp.sln` in Visual Studio 2022
4. In Visual Studio, right click the project `TouchEngineUESamp` and `Set as startup project`, it should appear in **Bold**.
![Set startup project](assets/ueSamples_startup.png?raw=true "Set startup project")
5. At the top of Visual Studio, you should see two drop down menus, set the configuration to `Development Editor` and the target platform to be `Win64`.
![Set configuration](assets/ueSamples_configuration.png?raw=true "Set configuration")
6. In Visual Studio, right click the solution and click on `Rebuild solution`.
![Rebuild solution](assets/ueSamples02.png?raw=true "Rebuild solution")
7. It could take a few minutes. Grab a cup of coffee.
8. Launch `TouchEngineUESamp.uproject` in Unreal Engine 5.2.0+

### Use release version

After cloning or downloading the archive of this repository, unzip and go to its root.

1. Go to the [release page](https://github.com/TouchDesigner/TouchEngine-UE/releases) and download the latest release zip file.
2. In the TouchEngine-UE Samples folder, unzip the downloaded file in `Plugins/`.
3. A folder named TouchEngine should now be here with a structure similar to the one in the following screenshot. ![Plugin folder structure](assets/ueSamples03.png?raw=true "Plugin folder structure")
4. Launch `TouchEngineUESamp.uproject` in Unreal Engine 5.2.0+