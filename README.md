# TouchEngineUE4Samp

Tested against TouchDesigner 2020.24520 and UE 4.25.1.

The TouchEngine plugin is referenced using a git submodule, so clone using

git clone --recurse gitURL

Rebuild the map/lighting to fix the error that comes up when loading the project.

Open the Level Blueprint to see the network of operations used to run TouchEngine.

***Important***
You will need to change the value of the Tox Path on the far left of the Level Blueprint
to print to the correct location of UnrealSample.tox on your local machine. Relative paths
don't work yet in the Plugin code.

The included UnrealSample.tox has 1 CHOP input, 1 CHOP output, and 1 TOP output. 

* The CHOP output outputs 3 channels which are random noise. In the level blueprint these
values are applied to a light that is close to the large darker colored cube in the scene.
* The CHOP input is used to to scale the brightness of the 3 values coming out of the CHOP output.
* The TOP output is just a texture of the regular displaced jellies.

Inputs and outputs are referenced by the node name of the In or Out OPs.
