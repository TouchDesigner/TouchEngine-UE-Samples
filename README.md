# TouchEngineUE4Samp

Tested against TouchDesigner 2020.26930 and UE 4.25.1.
2020.26930 is not available publicly as of Oct 13, 2020. Here is a direct download link:
https://www.dropbox.com/s/us0ntegthxw33s7/TouchDesigner.2020.26930.exe?dl=0

The TouchEngine plugin is referenced using a git submodule, so clone using

git clone --recurse gitURL

Rebuild the map/lighting to fix the error that comes up when loading the project.

Open the Level Blueprint to see the network of operations used to run TouchEngine.

***Important***
You will need to change the value of the Tox Path on the far left of the Level Blueprint
to print to the correct location of UnrealSample.tox on your local machine. Relative paths
don't work yet in the Plugin code.

The included UnrealSample.tox has 1 CHOP input, 1 CHOP output, 1 TOP output and 1 TOP input.

* The CHOP output outputs 3 channels which are random noise. In the level blueprint these
values are applied to a light that is close to the large darker colored cube in the scene.
* The CHOP input is used to to scale the brightness of the 3 values coming out of the CHOP output.
* The TOP output is a texture of the regular displaced jellies, along with whatever is sent into the TOP input as the other half of the input.
* The TOP input is combined with the output as half the image. The input currently comes from a RenderTexture that is generated on load 

***Current Features***
Currently only CHOP input/output and TOP input/output is programmed into the Plugin.
It only works with DX11 renderer so far. Although DX12 is partially working as well.

Inputs and outputs are referenced by the node name of the In or Out OPs.

***Note ***

TouchEngine takes approximately 5 seconds to load after level starts playing. 
