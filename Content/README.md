# Example files documentation

All .tox files can be found in `TDToxFiles`.

## 01 EnginePerform

Tox path and name: `Content\TDToxFiles\UESample01_EnginePerform.tox`

This example is showcasing how to load an Engine Component. The second part of the example is using the same base .tox file and loading in different sync modes.

It is also handy to see how the TouchEngine is running in its own thread has it is outputting all the data available with a Perform CHOP. Additonally, a pulsing circle is being driven by a Beat CHOP, as well as the current frame and absolute frame of the Timeline CHOP being passed to the final TOP output.

![TOX](ReadmePictures/01_EnginePerform_01.png?raw=true "EnginePerform .tox content.")

### Parameters, inputs, outputs

#### Parameters
None

#### Inputs
None

#### Outputs
- top_performData
- dat_performData
- chop_performData

In the blueprint, only the top_performData output is being used. The two other output formats, DAT and CHOP, are ready to be used to your liking by creating a new blueprint or editing the existing blueprint. All three outputs are based on the same data (a perfrom CHOP).

### .tox file
Self explenatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

TODO: To be completed

## 02 SimpleTexture

Tox path and name: `Content\TDToxFiles\UESample02_SimpleTexture.tox`

This simple example showcase how to stream a texture from TouchEngine and apply it in an Unreal Engine material. A similar approach is showcased in the example EnginePerform where we are applying the text

![TOX](ReadmePictures/02_SimpleTexture_01.png?raw=true "SimpleTexture .tox content.")

### Parameters, inputs, outputs

#### Parameters
- Name

#### Inputs
- chop_rgbBrightness
- top_textureIn

In this example, the first input chop_rgbBrithness is not used. It is here to showcase that a .tox can be loaded multiple times in different engines. You will see it being used in the Simple RGB Light example.

The second input can be used from within Unreal Engine to replace the jellybeans default texture by an Unreal Engine texture. It will then be displaced like in the traditional and default TouchDesigner project.

#### Outputs
- chop_rgbOut - RGB channels following a sinewave. They can be "dimmed" using the chop_rgbBrightness input. They are not used in this example (see previous section for details).
- top_textureOut - The displaced default jellybeans texture or an Unreal Engine texture assgined by the user.

### .tox file
Self explenatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

TODO: To be completed

## 03 Parameters

Tox path and name: `Content\TDToxFiles\UESample03_Parameters.tox`

This example showcase how to get or set all parameters type of TouchDesigner / TouchEngine within an Unreal Engine blueprint. There is no specific interactivity available here, but we advise users to focus on the blueprint file to understand the process behind each parameter get / set. Additionally, it covers all inputs / outputs type, but they are only passthrough without particular data processing.

### Parameters, inputs, outputs

#### Parameters
- Filepath
- Folderpath
- Header
- Position
- Colour
- Size
- Uvw
- Float
- String
- Int
- Intmenu
- Stringmenu
- Anotherheader
- Toggle
- Pulse
- Momentary
- Threeints

#### Inputs
- chop_in1
- dat_in1
- top_in1

#### Outputs
- chop_out1
- dat_out1
- top_out1

### .tox file
Self explenatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

TODO: To be completed

## 04 SimpleBlendCubeTexture

Tox path and name: `Content\TDToxFiles\UESample04_SimpleBlendCubeTexture.tox`

This example showcase the use of multiple TOP inputs and some simple TOP compositing (blend) between a TOP A and a TOP B. Use the Blend parameter to modify the blend factor.

![TOX](ReadmePictures/04_SimpleBlendCubeTexture_01.png?raw=true "SimpleBlendCubeTexture .tox content.")

### Parameters, inputs, outputs

#### Parameters
- Blend (Float Par)

#### Inputs
 - top_texA - by default using the traditional TouchDesigner banana. You can assign a texture in Unreal Engine after loading the .tox file. Texture can only be of an Unreal-friendly compression type. More details below.
 - top_texB - by default using the TouchDesigner cubemap / UV grid. You can assign a texture in Unreal Engine after loading the .tox file. Texture can only be of an Unreal-friendly compression type. More details below.
 - 
#### Outputs
- top_blendedTexture - the result of the blend

### .tox file
Self explenatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

TODO: To be completed

## 05 SingleSampleChannels

Tox path and name: `Content\TDToxFiles\UESample05_SingleSampleChannels.tox`

This simple example showcase the use of multiple channels of CHOP data with one sample per channel.

![TOX](ReadmePictures/05_SingleSampleChannels_01.png?raw=true "SingleSampleChannels .tox content.")

### Parameters, inputs, outputs

#### Parameters
None

#### Inputs
None

#### Outputs
- chop_singleSampleChannels

One single CHOP output, of 1024 channels of 1 sample each.

### .tox file
Self explenatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

TODO: To be completed

## 06 PulseGenerateRandomPositions

Tox path and name: `Content\TDToxFiles\UESample06_PulseGenerateRandomPositions.tox`

This example showcase the use of multiple channels of CHOP data with 100 samples per channel. The channels being outputted are tx, ty, tz. Using the Generate pulse parameter will generate a new data set. The change between data sets pre / post pulse is smoothed over 1 second with a filter CHOP.

![TOX](ReadmePictures/06_PulseGenerateRandomPositions_01.png?raw=true "PulseGenerateRandomPositions .tox content.")

### Parameters, inputs, outputs

#### Parameters
- Generate (Pulse Par)

#### Inputs
None

#### Outputs
- chop_randomPositions

One single CHOP output, of 3 channels of 100 samples each.

### .tox file
Self explenatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

TODO: To be completed

## 07 PulseGenerateRandomPath

Tox path and name: `Content\TDToxFiles\UESample07_PulseGenerateRandomPath.tox`

This example showcase the use of multiple channels of CHOP data with X samples per channel. X being the value set with the Resolution parameter. The channels being outputted are tx, ty, tz. Using the Generate pulse parameter will generate a new data set. The change between data sets pre / post pulse is smoothed over 1 second with a filter CHOP.

![TOX](ReadmePictures/07_PulseGenerateRandomPath_01.png?raw=true "PulseGenerateRandomPath .tox content.")

### Parameters, inputs, outputs

#### Parameters
- Resolution (Int Par)
- Generate (Pulse Par)

#### Inputs
None

#### Outputs
- chop_pathData
- chop_currentPathPosition

In this example, the chop_currentPathPosition is the only output being used by default. It is used to drive the position of one sphere along a path. You can use chop_pathData by using the same technique showcased in example 05.

### .tox file
The Resolution parameter is used to specify the length of multiple pattern CHOPs which will make up a path for a sphere to follow. When pulsing the Generate Par, a new seed is generated and saved from noise2 to be passed to the Pattern CHOPs as number of cycles. Finally, an LFO set as Ramp will scrub (with a lookup CHOP) the generated path over time.

### Blueprint, UE dataflow and specifics

TODO: To be completed

## 08 SpringData

Tox path and name: `Content\TDToxFiles\UESample08_SpringData.tox`

This CHOP data example is based on one of the Spring CHOP snippets available from within TouchDesigner. A trigger (Spring Trigger - Pulse Par) and various parameters related to the Spring CHOP are exposed at the top level. Additionally, an input CHOP can also be used to trigger the spring / rebound effect.

![TOX](ReadmePictures/08_SpringData_01.png?raw=true "SpringData .tox content.")

### Parameters, inputs, outputs

#### Parameters
See [Derivative.ca wiki documentation](https://docs.derivative.ca/Spring_CHOP).

At runtime and in realtime, the user can update the parameters to have an impact on the system. 

#### Inputs
- input_chopSpringTrigger - this input is binded to the right red button in the example project. Shooting on that button will pass a value going from 0 to 1 as CHOP data.

#### Outputs
- chop_springTriggerValue

In this example, chop_springTriggerValue is being used to drive the positions of a sphere on its height.

### .tox file
Self explenatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

TODO: To be completed

## 09 PointGenerator

Tox path and name: `Content\TDToxFiles\UESample09_PointGenerator.tox`

This more advanced example showcase the use of the Palette's pointGenerator to generate positions for X points where X is the value set using the Num Points parameter. For details about the pointGenerator, go to the following [page](https://docs.derivative.ca/Palette:pointGenerator).

![TOX](ReadmePictures/09_PointGenerator_01.png?raw=true "PointGenerator .tox content.")

### Parameters, inputs, outputs

#### Parameters
See [Derivative.ca wiki documentation](https://docs.derivative.ca/Palette:pointGenerator).

At runtime and in realtime, the user can update the parameters to have an impact on the system. 

#### Inputs
None

#### Outputs
- top_pointData - the data generated from the pointGenerator as a TOP texture, where RGB = T[XYZ]
- chop_pointData - the same data as top_pointData but in CHOP format.

In this example, top_pointData (TODO: Example to be fixed) is being used to drive the positions of the spheres. chop_pointData could be used in a similar fashion to example 05.

### .tox file
See pointGenerator wiki documentation for details. The .tox file is really just wrapping the palette component.

### Blueprint, UE dataflow and specifics

TODO: To be completed

## 10 SimpleScoring

Tox path and name: `Content\TDToxFiles\UESample10_SimpleScoring.tox`

This advanced example fully rely on DATs and TouchDesigner internal Python engine. While we could argue that there is tools for a scoring system in Unreal Engine, this is just an example of what can be done using DATs and Python.

![TOX](ReadmePictures/10_SimpleScoring_01.png?raw=true "SimpleScoring .tox content.")

### Parameters, inputs, outputs

#### Parameters
 - Players (Str Par) - a space delimited list of players
 - Index to update (Int Par) - used to specify which of the player in the space delimited list of players from the Player Par should be updated
 - Operator (Menu Par) - The operation to execute on the player set with Index to update
 - Points (Int Par) - the number of points to add or substract from the player total
 - Send (Pulse Par) - execute operation
 - Reset (Pulse Par) - Reset all players scores to 0

#### Inputs
None

#### Outputs
- dat_sortedDescScore - simple leaderboard in DAT format
- chop_sortedDescScore - a CHOP of X channels of 1 sample where X is the number of players, and the channel name is the name of the player. The sample is the current number of points of the player.

In this example, dat_sortedDescScore is being used to display text in Unreal Engine, where the list is ordered with the player with the best score at the top.

### .tox file
A simple scoring system relying on a mostly DAT network and Parameter Execute callbacks. Each time the pulse parameter Execute is pressed, the python script will fetch the current parameters at the COMP level to dstribute or substract points. The final DAT dat_sortedDescScore is outputting the leaderboard with the best player at the top.

### Blueprint, UE dataflow and specifics

TODO: To be completed

<!-- ## 00 TEMPLATE NAME

Tox path and name: `PATH TO TOX`

This simple example showcase... 

![TOX](ReadmePictures/01_EnginePerform_01.png?raw=true "EnginePerform .tox content.")

### Parameters, inputs, outputs

#### Parameters
- Name

#### Inputs
None

#### Outputs
- type_name

TODO: To be completed


### .tox file
TODO: To be completed

### Blueprint, UE dataflow and specifics

TODO: To be completed -->