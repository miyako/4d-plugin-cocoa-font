4d-plugin-cocoa-font
=============

Get information about fonts on Mac.

### Platform

| carbon | cocoa | win32 | win64 |
|:------:|:-----:|:---------:|:---------:|
|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|||

### Version

<img src="https://cloud.githubusercontent.com/assets/1725068/18940649/21945000-8645-11e6-86ed-4a0f800e5a73.png" width="32" height="32" /> <img src="https://cloud.githubusercontent.com/assets/1725068/18940648/2192ddba-8645-11e6-864d-6d5692d55717.png" width="32" height="32" />

## Syntax

```
FONT GET FAMILY NAMES (names)
```

Parameter|Type|Description
------------|------------|----
names|ARRAY TEXT|

```
FONT GET DISPLAY NAMES (names;option)
FONT GET NAMES (names;option)
```

Parameter|Type|Description
------------|------------|----
names|ARRAY TEXT|
option|LONGINT|``0`` for all fonts, or a combination of traits

* Font Traits

```c
FONT Italic (1)
FONT FixedPitch (1024)
FONT SmallCaps (128)
FONT Narrow (16)
FONT Unitalic (16777216)
FONT Bold (2)
FONT Poster (256)
FONT Expanded (32)
FONT Unbold (4)
FONT Compressed (512)
FONT Condensed (64)
FONT NonStandardCharacterSet (8)
```

```
name:=FONT Get localized name (family;face)
```

Parameter|Type|Description
------------|------------|----
family|TEXT|
face|TEXT|
name|TEXT|

```
displayName:=FONT Get display name (name)
```

Parameter|Type|Description
------------|------------|----
name|TEXT|
displayName|TEXT|

```
weight:=FONT Get weight (name)
```

Parameter|Type|Description
------------|------------|----
name|TEXT|
weight|LONGINT|

```
weight:=FONT Get traits (name)
```

Parameter|Type|Description
------------|------------|----
name|TEXT|
traits|LONGINT|

```
FONT GET INFORMATION (name;size;keys;values)
```

Parameter|Type|Description
------------|------------|----
name|TEXT|
size|LONGINT|
keys|ARRAY TEXT|``ascender``, ``descender``, ``capHeight``, ``leading``, ``italicAngle``, ``isFixedPitch``, ``underlinePosition``, ``underlineThickness``, ``xHeight``
values|ARRAY TEXT|

```
FONT GET FAMILY MEMBER NAMES (name;size;keys;values)
```

Parameter|Type|Description
------------|------------|----
name|TEXT|
names|ARRAY TEXT|
parts|ARRAY TEXT|``Roman``, ``Italic``, ``Bold``, etc.
weights|ARRAY LONGINT
traits|ARRAY LONGINT
