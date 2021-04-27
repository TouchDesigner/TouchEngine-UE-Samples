# Example files documentation

All .tox files can be found in `TDToxFiles`.

## 01 UnrealSample

### Parameters, inputs, outputs

The included UnrealSample.tox has 1 CHOP input, 1 CHOP output, 1 TOP output and 1 TOP input.

### .tox file

* The CHOP output outputs 3 channels which are random noise. In the level blueprint these
values are applied to a light that is close to the large darker colored cube in the scene.
* The CHOP input is used to to scale the brightness of the 3 values coming out of the CHOP output.
* The TOP output is a texture of the regular displaced jellies, along with whatever is sent into the TOP input as the other half of the input.
* The TOP input is combined with the output as half the image. The input currently comes from a RenderTexture that is generated on load

### Blueprint, UE dataflow and specifics