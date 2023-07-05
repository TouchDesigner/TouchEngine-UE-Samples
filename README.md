# TouchEngine For UE Plugin Samples Repository

* **Current Unreal Engine version:** `5.2.1`
* **Current TouchEngine version:** `2022.33910`
* **Current Plugin version:** `1.2.0`

The TouchEngine Plugin currently supports Custom Parameters, CHOP input/output, TOP input/output and DAT input/output.

> 💡 This repository is covering the sample project and examples, for a complete documentation of the TouchEngine For UE Plugin, follow [this link 🔗](https://github.com/TouchDesigner/TouchEngine-UE/).

* [Getting Started](docs/getting-started.md)
* [Samples Documentation](docs/samples.md)
* [FAQ](docs/FAQ.md)

## Samples

Open the Level Blueprint to see the network of operations used to run TouchEngine.

For a detailed walkthrough of the samples, [go here 🔗](docs/samples.md).

## Using a specific build of TouchEngine

By default, the TouchEngine build used by the Unreal Plugin will be from the most recently installed TouchDesigner on the system.

To override and use a specific build, the Unreal Plugin looks for a shortcut named “TouchEngine” when loading.

If you place any of the following, named "TouchEngine", alongside the .tox you're opening, it will use that build

- a Windows .lnk to a TouchDesigner installation
- a symlink to a TouchDesigner installation
- a full TouchDesigner installation

Lastly, you can also use the env variable `TOUCHENGINE_APP_PATH`.

## Known issues and current limitations

See release page for known issues on latest releases.

## TouchEngine For UE Plugin documentation

This repository is covering the sample project and examples, for a complete documentation of the TouchEngine For UE Plugin, follow [this link](https://github.com/TouchDesigner/TouchEngine-UE/).
