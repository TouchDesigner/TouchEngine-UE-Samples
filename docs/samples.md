# Example files documentation

All .tox files can be found in `Content\TDToxFiles` from the root folder of this repository.

All blueprints are in `Content\TouchEngineSample\Blueprints` from the root folder of this repository.

All the names should be self explanatory and be easy to match between .tox / blueprint / sample.

## A word about blueprints and UE project file

When cloning the repository and opening the project for the first time, pay attention to the World Outliner on the right. The World Outliner is carefully organized and objects are named so that you can easily connect the dots between .tox file and blueprints. 

In the following documentation, only the first sample will have its blueprint extensively documented, the following examples will cover specific bits that are specific to the example covered in that section.

Overall, blueprints are commented, and this is what you should mainly study, from within Unreal with the project loaded.

> 💡 If something is misunderstood, please come ask on our forum, so that it can benefit to the whole community.

## Find the .tox used

Every sample is using a TouchEngine Actor, with a TouchEngine Component being parented with.

When you click on a TouchEngine Actor, in the 3D world/viewport, or in the world outliner on the right, you can find details about the TouchEngine Component in the details panel, or by opening the blueprint / double clicking on this actor.

![Find .tox and BPs](assets/samples/intro_find_tox.png?raw=true "Find .tox and BPs")

See in the screenshot above.

(1) is what I clicked first in the world. This is a TouchEngine Actor. 
The same could have been easily achieved as well by clicking on (2), the same actor, in the world outliner.
Double clicking on (2) or clicking on (3) will open the blueprint in the editor.

But all we really need to find our .tox is actually here already. See (4), the details panel.

With the Actor (top level) selected, or the TouchEngine Component that you can see listed, find the TouchEngine Component section (4), and the Tox Asset property (4).

![Tox Asset and .tox path](assets/samples/intro_tox_asset_path.png?raw=true "Tox Asset and .tox path")

When you double click on the Tox Asset. You will see a new window opening where the File Path of the .tox file is present.

## Find the blueprint

In the similar fashion the the previous section "Find the .tox used". Click on a TouchEngine Actor, in the 3D world/viewport, or in the world outliner on the right. Double clicking on the actor or clicking on the "Type" (in blue, underlined) will open the blueprint directly in the blueprint editor.

Alternatively, you can right click the actor to get to the blueprint asset in the content browser.

## Samples

* Engine Component
    * Base
    * Sync Modes
* Parameters
    * Simple Parameters Get / Set
    * Parameters, all supported types r/w
    * Parameters + Par CHOP / DAT Outs
* TOPs
    * Texture Passthrough
    * Simple texture
    * Simple texture 16RGB
* CHOPs
    * Read from CHOPs
    * Write to CHOPs
    * CHOP Soup
    * Single Sample Channels
    * Pulse Generate Random Positions
    * Pulse Generate Random Path
    * Channel to light
* DATs
    * Scoring setup
* Mixed
    * Blend Cube Texture
    * Spring
    * Blend Cube Texture (w/ Fit)
    * Movie Player
    * Point Generator
* Other
    * Sync

### Engine Component - Base

This example is showcasing how to load a TouchEngine Component. The second part of the example is using the same base .tox file and loading in different sync modes.

It is also helpful to see how the TouchEngine is running in its own subprocess as it is outputting all the data available from a Perform CHOP. Additionally, a pulsing circle is being driven by a Beat CHOP, and the current frame and absolute frame of the Timeline CHOP are being passed to the final TOP output.

![TOX](assets/samples/01_EnginePerform_01.png?raw=true "EnginePerform .tox content.")

In the blueprint, only the top_performData output is being used. The two other output formats, DAT and CHOP, can be used by creating a new blueprint or editing the existing blueprint. All three outputs are based on the same data (a Perform CHOP).

### Engine Component - Base - In Details

You can easily access the blueprint in the World Outliner.

![TOX](assets/samples/01_EnginePerform_02.png?raw=true "EnginePerform in World Outliner.")

Each world object prefixed BP_TE_ is the blueprint where a TouchEngine Component is being used to load the example .tox file.

You can either click directly Edit BP_TE_[example name] or click the object and look for the details panel underneath.

![TOX](assets/samples/01_EnginePerform_03.png?raw=true "EnginePerform BP_TE_ in Details Panel.")

You will find in the components section of the details panel the TouchEngine Component, with all the parameters of the .tox file loaded being exposed, as well as inputs (CHOPs, DATs, TOPs) and outputs.

![TOX](assets/samples/01_EnginePerform_04.png?raw=true "EnginePerform TouchEngine component details in Details Panel.")

Clicking Edit BP_TE_[example name] brings up the blueprint editor in a new window. In this window, you can find the same objects that make the blueprint and were visible in the details panel. Clicking the TouchEngine Component displays the TouchEngine settings in the details panel, as well as parameters, inputs and outputs.

![TOX](assets/samples/01_EnginePerform_05.png?raw=true "EnginePerform blueprint editing window view.")

You can see in this blueprint example that we are fetching the output of the loaded TouchEngine component using Get TouchEngine Output and by setting the output name o/top_performData. Once fetched, the TOP (in TouchDesigner slang) or Texture Object Reference (in Unreal Engine slang) is applied to a Dynamic Material using Set Texture Parameter Value. The result, in Play Mode in the World View, is a plane with a texture applied. The texture is the TOP output of the .tox file described in the sections above.

### A note about BP_ToggleButton_Loader

Note how in the World Outliner and in every sample, there is an object called ToggleButton_Loader using the blueprint BP_ToggleButton_Loader. This simple blueprint is used to trigger the load of the TouchEngine Component and .tox file within the TouchEngine.

The second part of this example showcases Cook Modes. The same object is used and referencing multiple instances of the same EnginePeform blueprint but each has a different Cook Mode set.

![TOX](assets/samples/01_EnginePerform_06.png?raw=true "EnginePerform ToggleButton loader details panel.")

Notice the property `Send Mode` on the TouchEngine Component. There are 2 send modes, Every Frame and On Access. Every Frame sets and gets outputs every frame, while on access only sends them when the variable types are accessed via the blueprint nodes.

## Parameters

### 01 - Simple Parameters Get / Set

This sample showcase how to use parameters from within a blueprint. It shows how to set parameters values or get the current parameter value using the Set / Get TouchEngine Parameter Nodes.

It shows how to use the basic parameter types.

The values are printed out for users to see changes and debug values.

When interacting with the details panel properties, you should see the values being printed out changing.

### 02 - Parameters, all supported types r/w

This sample is similar to the previous sample, the difference is that it shows how to use all supported parameter types.

### 02b - Parameters + Par CHOP / DAT Outs

This is using the same .tox file and a blueprint very similar to the previous sample, 02. It is also using a CHOP and a DAT output to show display the same parameter values as set in the TouchEngine, passed out uisng internally a Parameter CHOP and a Parameter DAT.

## TOPs

> 💡 Additional informations are available in the Plugin's repository documentation. Users should head to the TouchEngine-UE repository -> docs -> how-tos -> work-with-TOPs.md

### 01 - Texture Passthrough

This simple example showcases how to stream a texture from TouchEngine and apply it to an Unreal Engine material. A similar workflow is also showcased in the very first sample, "Engine Component" where we are applying the text (as texture) output of the TouchEngine component being loaded to a material.

While loading the sample will show the familiar TouchDesigner Jellybeans, you can assign an Unreal Engine texture to the input, through the Details Panel, and see it being passed through the TouchEngine.

### 02 - Simple Texture

This example showcases a texture being sent out of a running TouchEngine to be used in Unreal.

### 02b - Simple Texture

This example is the same as the previous sample, to the difference that is is using a different pixel format within the TouchEngine subprocess.

The Material used is different to accomodate the different texture format. Our texture here is not 8bit, so the Material used is using a Linear Color sampler rather than the Color sampler used so far. 

> 💡 **NOTE: A word about texture type, depth and limitations** 
>
> ⚠️ Pay attention to the Material used in each case where textures are being passed in to TouchEngine or expecially received from TouchEngine to be used in UE. They are tweaked based on the content being passsed in / out, and the texture format.
>
> When importing textures (assets) in Unreal Engine, there is a chance that the default type automatically set by UE will not be compatible with TouchEngine. Please open an issue on Github and share your texture file in a .zip if you encounter issues with a specific file.
>
> Accessing a TouchEngine Component TOP output should always work and be converted to the appropriate texture type in the Unreal blueprint.

### 03 - Render Target

This sample showcase the use of a Render Target as Input to TouchEngine.

In the blueprint, the SceneCaptureComponent2D is a camera and capturing frames from this POV. The frames are being written as 32bit floats RGBA to a texture render target "RT_TouchEngine" and this is being sent to TouchEngine.

The texture is distorted in the running TouchEngine and outputted back into Unreal, and applied to the material of a plane.

## CHOPs

> 💡 Users are invited to spend time looking at the (commented) blueprints for tips and tricks, and going through different approaches.

### 01 - Read from CHOPs

This extensive sample shows how to use data coming from a CHOP output. Whether we are working with multiple channels of one sample, a channel of many samples, or multiple channels of many samples - everything should be covered and get you going with that sample.

### 02 - Write to CHOPs

This extensive sample shows how to prepare data to be CHOP ready. It is also using, in PIE only, the position of the player pawn, being fed to the TouchEngine. The value is passed through and the output is being printed out.

It also showcase how to work with CHOP objects, CHOP Channels and set multiple CHOP inputs.

### 03 - CHOP Soup

This sample is a mix of the previous samples. The data being passed to TouchEngine is processed and worked on within the TouchEngine process to be pushed out in a different setup.

### 04 - Single Sample Channels

This simple example showcases the use of multiple channels of CHOP data with one sample per channel.

You can see in the blueprint event graph that Get TouchEngine Output will pass to the blueprint a CHOP object. In this case, the 1024 channels of 1 sample each are used to drive the distance between the center of our "shape" and all the satellites.

Lastly, the gathered data is being passed to BP_OrbiterCubes and its Set Satellite Distances function where instances are being created and transforms set. The approach is identical in example 06, 07 and 09.

### 05 - Pulse Generate Random Positions

This example showcases the use of multiple channels of CHOP data with 100 samples per channel. The channels being outputted are tx, ty, tz. Using the Generate pulse parameter will generate a new data set. The change between data sets pre / post pulse is smoothed over 1 second with a filter CHOP.

This example is briefly setting a Pulse parameter on the hit event using Set TouchEngine Parameter. The pulse generates new positions within the TouchEngine / .tox loaded and Unreal Engine reads those values back using Get TouchEngine Output.

A CHOP object is returned from Get TouchEngine Output. This CHOP object is passed (as a reference) to Fill Pos Array to be parsed and prepared in an Unreal Engine friendly format: an array of transforms.

> 💡 Note: The Fill Pos Array BP is showcasing the Get Channel node, as well as the Break nodes.

### 06 - Pulse Generate Random Path

This example showcases the use of multiple channels of CHOP data with X samples per channel. X being the value set with the Resolution parameter. The channels output are tx, ty, tz. Using the Generate pulse parameter will generate a new data set. The change between data sets pre / post pulse is smoothed over 1 second with a filter CHOP.

In this example, the chop_currentPathPosition is the only output being used by default. It is used to drive the position of one sphere along a path. You can use chop_pathData by using the same technique showcased in example 05.

The Resolution parameter is used to specify the length of multiple Pattern CHOPs which will make up a path for a sphere to follow. When pulsing the Generate Par, a new seed is generated and saved from noise2 to be passed to the Pattern CHOPs as number of cycles. Finally, an LFO set as Ramp will scrub (with a Lookup CHOP) the generated path over time.

### 07 - Channel to light

Here the user can drive the brightness of a light using the engine input `chop_rgbBrightness`. The output `chop_rgbOut` with 3 channels (R, G, B) of 1 sample each is being used to drive the light color output.

## DATs
### 01 - Scoring Setup

This advanced example uses DATs and TouchDesigner’s Python engine. While one could argue that there are tools for a scoring system in Unreal Engine, this is an example of using DATs and Python to create logic systems in TouchDesigner that can be used directly in Unreal Engine.

> 💡 In 1.2.0, the .tox also adds an input that will pass the values to a Touch Out DAT. It is currently used only as a diagnostic tool. DAT support only array of strings at the moment, which translate to a single column.

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

#### .tox file
A simple scoring system relying on a mostly DAT network and Parameter Execute callbacks. Each time the pulse parameter Execute is pressed, the python script will fetch the current parameters at the COMP level to distribute or subtract points. The final DAT dat_sortedDescScore is outputting the leaderboard with the best player at the top.

#### Blueprint, UE dataflow and specifics

This example relies heavily on the details panel.

When shooting the button, the Send parameter (Pulse type) is briefly set to 1 and the .tox file loaded in the TouchEngine Component will do the work based on all the other parameters of the details panel.

The blueprint is reading the DAT output using Get TouchEngine Output (o/dat_sortedDescScore) where a DAT object is returned, before calling the Set Score Text blueprint function.

Using the DAT object, Set Score Text blueprint is looping over rows and columns using the Get Cell plugin method to recreate the DAT as text objects within Unreal Engine.


## Mixed
### 01 - Blend Cube Texture

This example showcases the use of multiple TOP inputs and some simple TOP compositing between a TOP A and a TOP B. Use the Blend parameter to modify the blend factor.

It make uses of nodes that you are already familiar with by now. It's showcasing how to change the value of a parameter (type float in that case) using Set TouchEngine Input (from Update Blend Value). In this example, the interaction is triggered when you shoot at the arrows on the sides of the box. It will increase or decrease the value passed to the Blend parameter. You can also use Unreal Engine textures which will replace the default (Banana and UV board) textures.

### 01b - Blend Cube Texture

This sample is the same as the previous sample. The difference is that any texture applied will go through a Fit TOP internally, to avoid having the blend "jump" passing midpoint, because of a difference in texture resolution.

### 02 - Movie Player

This sample is relying on the palette's movieEngine Component. In the blueprint, it's mostly just using the texture output, similarly to the TOP samples seen previously.
You can use the parameters exposed to playback different video files and control playback.

### 04 - Point Generator

This more advanced example showcases the use of the Palette's pointGenerator to generate positions for X points where X is the value set using the Num Points parameter. For details about the pointGenerator, see the following [page](https://docs.derivative.ca/Palette:pointGenerator).

At runtime and in real-time, the user can update the parameters to have an impact on the system.

The implementation is similar to the CHOP samples involving spheres / cubes.

> ⚠️ This sample is using CHOP samples to place the object instances into space. While this was optimized, this is scaling poorly and will be come largely inefficient with large datasets. The Niagara samples should be looked into when considering texture sampling.

## 05 - Spring

This CHOP data example is based on one of the Spring CHOP snippets available from within TouchDesigner. A trigger (Spring Trigger - Pulse Par) and various parameters related to the Spring CHOP are exposed at the top level. Additionally, an input CHOP can also be used to trigger the spring / rebound effect.

At runtime and in realtime, the user can update the parameters to have an impact on the system. 

Similar to the Pulse button, this example is using one button where CHOP data is briefly set from 0 to 1 and passed to TouchEngine, while the other is setting a Pulse parameter. The effect on the visual elements is the same (it triggers the motion of the sphere).

## Niagara
### 01

This sample is showcasing how to use a 32bit TOP texture generated in TouchEngine (in this case, loading by default a .ply file) where very pixel is a position  where they are continuously rotating over time. The positions are sampled in Niagara, Unreal advanced particle system engine, and used as the base position for each particles. This is mostly a 1:1 representation of the .ply file as if it was seen as points in TouchDesigner.

### 02

The approach of that sample is the same as the previous sample. Instead of loading a .ply file, we are generating positions using Noise TOP, sent to Unreal as 32bit texture. Those pixels are sampled and used as positions and colors to particles in Niagara. The Niagara particle system is tweaked in comparison to the previous sample, the particles final positions are not a 1:1 match against the sampled texture. 