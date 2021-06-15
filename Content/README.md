# Example files documentation

All .tox files can be found in `Content\TDToxFiles` from the root folder of this repository.

## A word about blueprints and UE project file

When cloning the repository and opening the project for the first time, pay attention to the World Outliner on the right. The World Outliner is carefully organized and objects are named so that you can easily connect the dots between .tox file and blueprints. In the following documentation, only the first sample will have its blueprint extensively documented, the following examples will cover specific bits that are specific to the example covered in that section.

## 01 EnginePerform

Tox path and name: `Content\TDToxFiles\UESample01_EnginePerform.tox`

This example is showcasing how to load a TouchEngine Component. The second part of the example is using the same base .tox file and loading in different sync modes.

It is also helpful to see how the TouchEngine is running in its own thread as it is outputting all the data available from a Perform CHOP. Additionally, a pulsing circle is being driven by a Beat CHOP, and the current frame and absolute frame of the Timeline CHOP are being passed to the final TOP output.

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

In the blueprint, only the top_performData output is being used. The two other output formats, DAT and CHOP, can be used by creating a new blueprint or editing the existing blueprint. All three outputs are based on the same data (a Perform CHOP).

### .tox file
Self explanatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

You can easily access the blueprint in the World Outliner.

![TOX](ReadmePictures/01_EnginePerform_02.png?raw=true "EnginePerform in World Outliner.")

Each world object prefixed BP_TE_ is the blueprint where a TouchEngine Component is being used to load the example .tox file.

You can either click directly Edit BP_TE_[example name] or click the object and look for the details panel underneath.

![TOX](ReadmePictures/01_EnginePerform_03.png?raw=true "EnginePerform BP_TE_ in Details Panel.")

You will find in the components section of the details panel the TouchEngine Component, with all the parameters of the .tox file loaded being exposed, as well as inputs (CHOPs, DATs, TOPs) and outputs.

![TOX](ReadmePictures/01_EnginePerform_04.png?raw=true "EnginePerform TouchEngine component details in Details Panel.")

Clicking Edit BP_TE_[example name] brings up the blueprint editor in a new window. In this window, you can find the same objects that make the blueprint and were visible in the details panel. Clicking the TouchEngine Component displays the TouchEngine settings in the details panel, as well as parameters, inputs and outputs.

![TOX](ReadmePictures/01_EnginePerform_05.png?raw=true "EnginePerform blueprint editing window view.")

You can see in this blueprint example that we are fetching the output of the loaded TouchEngine component using Get TouchEngine Output and by setting the output name o/top_performData. Once fetched, the TOP (in TouchDesigner slang) or Texture Object Reference (in Unreal Engine slang) is applied to a Dynamic Material using Set Texture Parameter Value. The result, in Play Mode in the World View, is a plane with a texture applied. The texture is the TOP output of the .tox file described in the sections above.

### A note about BP_ToggleButton_Loader

Note how in the World Outliner and in every sample, there is an object called ToggleButton_Loader using the blueprint BP_ToggleButton_Loader. This simple blueprint is used to trigger the load of the TouchEngine Component and .tox file within the TouchEngine.

The second part of this example showcases Cook Modes. The same object is used and referencing multiple instances of the same EnginePeform blueprint but each has a different Cook Mode set.

![TOX](ReadmePictures/01_EnginePerform_06.png?raw=true "EnginePerform ToggleButton loader details panel.")

Notice the property `Send Mode` on the TouchEngine Component. There are 2 send modes, Every Frame and On Access. Every Frame sets and gets outputs every frame, while on access only sends them when the variable types are accessed via the blueprint nodes.

## 02 SimpleTexture

Tox path and name: `Content\TDToxFiles\UESample02_SimpleTexture.tox`

This simple example showcases how to stream a texture from TouchEngine and apply it in an Unreal Engine material. A similar approach is showcased in the previous example EnginePerform where we are applying the text.

![TOX](ReadmePictures/02_SimpleTexture_01.png?raw=true "SimpleTexture .tox content.")

### Parameters, inputs, outputs

#### Parameters
- Name

#### Inputs
- chop_rgbBrightness
- top_textureIn

In this example, the first input chop_rgbBrightness is not used. It is here to showcase that a .tox can be loaded multiple times in different engines. You will see it also being used in the Simple RGB Light example.

The second input can be used from within Unreal Engine to replace the jellybeans default texture by an Unreal Engine texture. It will then be displaced like in the default TouchDesigner project.

#### Outputs
- chop_rgbOut - RGB channels following a sinewave. They can be "dimmed" using the chop_rgbBrightness input. They are not used in this example (see previous section for details).
- top_textureOut - The displaced default jellybeans texture or an Unreal Engine texture assigned by the user.

### .tox file
Self explanatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

This example is getting a texture out of the TouchEngine and applying it to a cube, using the nodes Get TouchEngine Output (to get the TOP out of the TouchEngine) and Set Texture Parameter Value to set the texture on the cube.

The main difference here is that you can also pass a texture from Unreal Engine to TouchEngine, using Set TouchEngine Input. Any texture passed using this node will be used just like a standard TOP input on a Component in TouchEngine.

You can do anything you wish with it from within the TouchEngine process / .tox file, and output it again back to Unreal Engine.

![BP](ReadmePictures/02_SimpleTexture_02.png?raw=true "SimpleTexture setting TOP input from Unreal to TouchEngine.")

### A word about texture type, depth and limitations

When importing textures (assets) in Unreal Engine, there is high chances that the default type automatically set by UE will not be compatible with TouchEngine. You'll want to make sure your asset is in VectorDisplacementmap mode (RGBA8, 8bits) or HDR mode (RGB, no sRGB, 32bits). Uncompressed textures should all work. Please open an issue on Github and share your texture file in a .zip if you encounter issues with a specific file.

Accessing a TouchEngine Component TOP output should always work and be converted to the appropriate texture type in the Unreal blueprint.

## 03 Parameters

Tox path and name: `Content\TDToxFiles\UESample03_Parameters.tox`

This example showcases how to get or set all parameter types of TouchDesigner / TouchEngine within an Unreal Engine blueprint. There is no specific interactivity available here, but we advise users to focus on the blueprint file to understand the process behind each parameter get / set. Additionally, it covers all input / output types, but they are only passthrough without particular data processing.

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
Self explanatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

From the World Outliner, click on edit blueprint to access to the blueprint. It showcases how to read / write all parameter types and should be self explanatory.

![BP](ReadmePictures/03_Parameters_BP_Overall.png?raw=true "Parameters usage example in Parameters Blueprint")


## 04 SimpleBlendCubeTexture

Tox path and name: `Content\TDToxFiles\UESample04_SimpleBlendCubeTexture.tox`

This example showcases the use of multiple TOP inputs and some simple TOP compositing between a TOP A and a TOP B. Use the Blend parameter to modify the blend factor.

![TOX](ReadmePictures/04_SimpleBlendCubeTexture_01.png?raw=true "SimpleBlendCubeTexture .tox content.")

### Parameters, inputs, outputs

#### Parameters
- Blend (Float Par)

#### Inputs
 - top_texA - by default uses the TouchDesigner banana image. You can assign a texture in Unreal Engine after loading the .tox file. Texture can only be of an Unreal-friendly compression type. More details below.
 - top_texB - by default uses the TouchDesigner cubemap / UV grid image. You can assign a texture in Unreal Engine after loading the .tox file. Texture can only be of an Unreal-friendly compression type. More details below.

#### Outputs
- top_blendedTexture - the result of the blend

### .tox file
Self explanatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

This example showcases Unreal Engine nodes that you are already familiar with by now. It's showcasing how to change the value of a parameter (type float in that case) using Set TouchEngine Input (from Update Blend Value). In this example, the interaction is triggered when you shoot at the arrows on the sides of the box. It will increase or decrease the value passed to the Blend parameter. You can also use Unreal Engine textures which will replace the default (Banana and UV board) textures.

![TOX](ReadmePictures/04_SimpleBlendCubeTexture_02.png?raw=true "SimpleBlendCubeTexture Slider button left and right arrow interaction and setting parameter in blueprint.")
![TOX](ReadmePictures/04_SimpleBlendCubeTexture_02bis_UpdateBlendValue.png?raw=true "SimpleBlendCubeTexture Slider button left and right arrow interaction and setting parameter in blueprint.")

## 05 SingleSampleChannels

Tox path and name: `Content\TDToxFiles\UESample05_SingleSampleChannels.tox`

This simple example showcases the use of multiple channels of CHOP data with one sample per channel.

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
Self explanatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

This example introduces CHOPs in UE blueprints. You can see from the screenshot below or directly in the blueprint event graph that Get TouchEngine Output will pass to the blueprint a CHOP object. In this case, the 1024 channels of 1 sample each are used to drive the distance between the center of our "shape" and all the satellites.

![TOX](ReadmePictures/05_SingleSampleChannels_02.png?raw=true "Introducing CHOP objects in UE blueprints.")

Lastly, the gathered data is being passed to BP_OrbiterCubes and its Set Satellite Distances function where instances are being created and transforms set. The approach is identical in example 06, 07 and 09. 09 Will be updated at a later date to use 32-bit texture data.

## 06 PulseGenerateRandomPositions

Tox path and name: `Content\TDToxFiles\UESample06_PulseGenerateRandomPositions.tox`

This example showcases the use of multiple channels of CHOP data with 100 samples per channel. The channels being outputted are tx, ty, tz. Using the Generate pulse parameter will generate a new data set. The change between data sets pre / post pulse is smoothed over 1 second with a filter CHOP.

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
Self explanatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

Similar to the previous examples with the side arrows, this example is briefly setting a Pulse parameter on the hit event using Set TouchEngine Input. The pulse generates new positions within the TouchEngine / .tox loaded and Unreal Engine reads those values back using Get TouchEngine Output.

![TOX](ReadmePictures/06_PulseGenerateRandomPositions_02.png?raw=true "PulseGenerateRandomPositions set Pulse Par from Unreal Engine blueprint.")

A CHOP object is returned from Get TouchEngine Output. This CHOP object is passed to Fill Pos Array to be parsed and prepared in an Unreal Engine friendly format: an array of vectors. 

![TOX](ReadmePictures/06_PulseGenerateRandomPositions_03.png?raw=true "PulseGenerateRandomPositions set Pulse Par from Unreal Engine blueprint.")

In the following screenshot you can see that the Get Channel function can be used to retrieve a specific channel by its index.

![TOX](ReadmePictures/06_PulseGenerateRandomPositions_04.png?raw=true "PulseGenerateRandomPositions set Pulse Par from Unreal Engine blueprint.")


## 07 PulseGenerateRandomPath

Tox path and name: `Content\TDToxFiles\UESample07_PulseGenerateRandomPath.tox`

This example showcases the use of multiple channels of CHOP data with X samples per channel. X being the value set with the Resolution parameter. The channels output are tx, ty, tz. Using the Generate pulse parameter will generate a new data set. The change between data sets pre / post pulse is smoothed over 1 second with a filter CHOP.

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
The Resolution parameter is used to specify the length of multiple Pattern CHOPs which will make up a path for a sphere to follow. When pulsing the Generate Par, a new seed is generated and saved from noise2 to be passed to the Pattern CHOPs as number of cycles. Finally, an LFO set as Ramp will scrub (with a Lookup CHOP) the generated path over time.

### Blueprint, UE dataflow and specifics

Similar to the two previous examples.

## 02 SimpleTexture - RGB Light

Tox path and name: `Content\TDToxFiles\UESample02_SimpleTexture.tox`

This simple example showcases how multiple engines can load the same .tox file for different purposes or end results as this .tox file was also loaded in “Example 02 Simple Texture” above. Here the user can drive the brightness of a light using the engine input `chop_rgbBrightness`. The output `chop_rgbOut` with 3 channels (R, G, B) of 1 sample each is being used to drive the light color output.

### Parameters, inputs, outputs

#### Parameters
See 02 SimpleTexture section.

#### Inputs
See 02 SimpleTexture section.

#### Outputs
See 02 SimpleTexture section.

### .tox file
See 02 SimpleTexture section.

### Blueprint, UE dataflow and specifics

![BP](ReadmePictures/02_SimpleTexture_RGB_GetChannelByName_01.png?raw=true "You can also get a channel by its name.")

This example showcase how to access a CHOP channel by its name using Get Channel by Name.

## 08 SpringData

Tox path and name: `Content\TDToxFiles\UESample08_SpringData.tox`

This CHOP data example is based on one of the Spring CHOP snippets available from within TouchDesigner. A trigger (Spring Trigger - Pulse Par) and various parameters related to the Spring CHOP are exposed at the top level. Additionally, an input CHOP can also be used to trigger the spring / rebound effect.

![TOX](ReadmePictures/08_SpringData_01.png?raw=true "SpringData .tox content.")

### Parameters, inputs, outputs

#### Parameters
See [Derivative.ca wiki documentation](https://docs.derivative.ca/Spring_CHOP).

At runtime and in realtime, the user can update the parameters to have an impact on the system. 

#### Inputs
- input_chopSpringTrigger - this input is bound to the right red button in the example project. Shooting  that button will pass a value going from 0 to 1 as CHOP data.

#### Outputs
- chop_springTriggerValue - being used to drive the position of a sphere vertically.

### .tox file
Self explanatory. See comments of previous sections.

### Blueprint, UE dataflow and specifics

Similar to the Pulse button, this example is using one button where CHOP data is briefly set from 0 to 1 and passed to TouchEngine, while the other is setting a Pulse parameter. The effect on the visual elements is the same (it triggers the motion of the sphere). 

![TOX](ReadmePictures/08_SpringData_02.png?raw=true "SpringData .tox content.")

## 09 PointGenerator

Tox path and name: `Content\TDToxFiles\UESample09_PointGenerator.tox`

This more advanced example showcases the use of the Palette's pointGenerator to generate positions for X points where X is the value set using the Num Points parameter. For details about the pointGenerator, see the following [page](https://docs.derivative.ca/Palette:pointGenerator).

![TOX](ReadmePictures/09_PointGenerator_01.png?raw=true "PointGenerator .tox content.")

### Parameters, inputs, outputs

#### Parameters
See [Derivative.ca wiki documentation](https://docs.derivative.ca/Palette:pointGenerator).

At runtime and in real-time, the user can update the parameters to have an impact on the system.

#### Inputs
None

#### Outputs
- top_pointData - the data generated from the pointGenerator as a TOP texture, where RGB = T[XYZ]
- chop_pointData - the same data as top_pointData but in CHOP format.

In this example, top_pointData (TODO: Example to be fixed) is being used to drive the positions of the spheres. chop_pointData could be used in a similar fashion to example 05.

### .tox file
See pointGenerator wiki documentation for details. The .tox file is really just wrapping the palette component.

### Blueprint, UE dataflow and specifics

Currently, the approach is similar to example 07. The difference is in the amount of parameters being used, fetched from and being passed back to the TouchEngine. 09 Will be updated at a later date to use 32-bit texture data.

![TOX](ReadmePictures/09_PointGenerator_02.png?raw=true "Get CHOP before preparing data, passing data to satellites.")

![TOX](ReadmePictures/09_PointGenerator_03.png?raw=true "Parse CHOP data and ingest for Unreal friendly positions")

## 10 SimpleScoring

Tox path and name: `Content\TDToxFiles\UESample10_SimpleScoring.tox`

This advanced example uses DATs and TouchDesigner’s Python engine. While one could argue that there are tools for a scoring system in Unreal Engine, this is an example of using DATs and Python to create logic systems in TouchDesigner that can be used directly in Unreal Engine.

![TOX](ReadmePictures/10_SimpleScoring_01.png?raw=true "SimpleScoring .tox content.")

### Parameters, inputs, outputs

#### Parameters
 - Players (Str Par) - a space delimited list of players
 - Index to update (Int Par) - used to specify which  player in the space delimited list of players from the Player Par should be updated
 - Operator (Menu Par) - the operation to execute on the player set with Index to update
 - Points (Int Par) - the number of points to add or subtract from the player total
 - Send (Pulse Par) - execute operation
 - Reset (Pulse Par) - reset all players scores to 0

#### Inputs
None

#### Outputs
- dat_sortedDescScore - simple leaderboard in DAT format
- chop_sortedDescScore - a CHOP of X channels of 1 sample where X is the number of players, and the channel name is the name of the player. The sample is the current number of points of the player.

In this example, dat_sortedDescScore is being used to display text in Unreal Engine, where the list is ordered with the player with the best score at the top.

### .tox file
A simple scoring system relying on a mostly DAT network and Parameter Execute callbacks. Each time the pulse parameter Execute is pressed, the python script will fetch the current parameters at the COMP level to distribute or subtract points. The final DAT dat_sortedDescScore is outputting the leaderboard with the best player at the top.

### Blueprint, UE dataflow and specifics

This example relies heavily on the details panel.

![TOX](ReadmePictures/10_SimpleScoring_02.png?raw=true "SimpleScoring .tox content.")

When shooting the button, the Send parameter (Pulse type) is briefly set to 1 and the .tox file loaded in the TouchEngine Component will do the work based on all the other parameters of the details panel.

The blueprint is reading the DAT output using Get TouchEngine Output (o/dat_sortedDescScore) where a DAT object is returned, before calling the Set Score Text blueprint function.

![TOX](ReadmePictures/10_SimpleScoring_03.png?raw=true "SimpleScoring event graph in Unreal Engine blueprint.")

Using the DAT object, Set Score Text blueprint is looping over rows and columns using the Get Cell plugin method to recreate the DAT as text objects within Unreal Engine.

![TOX](ReadmePictures/10_SimpleScoring_04.png?raw=true "SimpleScoring Set Score Text function in Unreal Engine blueprint.")


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
