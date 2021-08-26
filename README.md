# RPGe 4U&Me

RPGe 4U&Me stands for "Role Playing Game engine for You & Me". Rolls right off the tongue.

This repo is in development and key features are not implemented yet.

This repo was forked from my other repo [LDtk-D11](https://github.com/dontpanic5/LDtk-D11). That repo provides the bare functionality of rendering LDtk worlds in DirectX 11. This repo builds upon that functionality and aims to provide an engine for RPGs. An important distinction to make is that there is no plan to provide the scene graph or level editor functionality associated with most game engines. [LDtk](https://github.com/deepnight/ldtk) fills the role of a level editor as RPGe 4U&Me uses ldtk format files. Because of the lack of provided developer UI, this project can also be viewed as a game framework.

## LDtk Integration

Pass as a command line argument a local LDTK file to render and all layers will be rendered using referenced icon or sprite textures. Entities with patrols will move along their patrol routes.



https://user-images.githubusercontent.com/242570/129111903-88727f39-9e21-45cb-bc76-a5d7975a4a9c.mp4



## Loading Game Data in JSON

Two types of data can be loaded into a game from a JSON format. This data is loaded at runtime from specified json files. JSON schemas are provided to describe the expected format of these files.
### Bestiary
Information about beasts, monsters, NPCs, adversaries, daemons, fairies, fey... you get the idea. Any entity you wish to provide stats for should have that data stored in a file bestiary.json. The schema file for beastiary.json files is bestiary.schema.json.
### Dialogue
Verbal interactions. Dialogue is assigned to the "actor" that will be interacted with. For example, a shopkeeper who is approached by the player character will store the dialogue that occurs when they are interacted with. This may include dialogue from the player or any other actor that participates in the dialogue, but it's dialogue that 'belongs' to the shopkeeper. Dialogue can even belong to inanimate objects, if they spark dialogue when interacted with. Monologues can also be stored as dialogue (I know they're not the same, shut up).
Dialogue is seperated into two kinds: "defaults" that are acted when no special conditions are true, and "specials" that are acted when a special condition evaluates true.

Use CMake to build, current dependencies are:
* directxtk (https://github.com/microsoft/DirectXTK). Available on [VCPKG](vcpkg.io).
* directxmath. Availble on [VCPKG](vcpkg.io).
* LDtkLoader (https://github.com/Madour/LDtkLoader).
