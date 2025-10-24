# Unreal Engine MQTT Properties Fix

This repository contains fixes for Unreal Engine property initialization errors in MQTT utility classes.

## Problem

The following errors were occurring when starting Unreal Engine:

```
LogClass: Error: BoolProperty FMqttMessage::Retain is not initialized properly. Module:MqttUtilities File:Public/Entities/MqttMessage.h
LogClass: Error: IntProperty FMqttMessage::Qos is not initialized properly. Module:MqttUtilities File:Public/Entities/MqttMessage.h
LogClass: Error: IntProperty FMqttClientConfig::Port is not initialized properly. Module:MqttUtilities File:Public/Entities/MqttClientConfig.h
```

## Solution

The properties in the USTRUCT definitions were not properly initialized. In Unreal Engine, UPROPERTY members in USTRUCT need to be initialized either:

1. **With default member initializers** (C++11 style): `bool Retain = false;`
2. **In the constructor**: Within the struct's constructor body

This fix implements BOTH approaches to ensure maximum compatibility:

- Default member initializers: `bool Retain = false;`, `int32 Qos = 0;`, `int32 Port = 1883;`
- Constructor initialization: All members are also initialized in the constructor

## Files Fixed

- `Public/Entities/MqttMessage.h` - Fixed `Retain` and `Qos` properties
- `Public/Entities/MqttClientConfig.h` - Fixed `Port` property

## How to Use

1. Copy the header files from `Public/Entities/` to your Unreal Engine plugin's `Public/Entities/` directory
2. Regenerate your Unreal Engine project files:
   - Close Unreal Engine Editor
   - Right-click your `.uproject` file and select "Generate Visual Studio project files"
3. Recompile your project:
   - Open the solution in Visual Studio
   - Build the solution (Ctrl+Shift+B)
4. Launch Unreal Engine - the errors should be resolved

## Notes

After modifying these header files, you DO need to recompile the binary files. Unreal Engine's reflection system (UPROPERTY, USTRUCT, etc.) requires compilation to update the generated code.

### Chinese (中文说明)

在修改这些头文件后，您需要重新生成二进制文件。虚幻引擎的反射系统（UPROPERTY、USTRUCT等）需要编译才能更新生成的代码。

步骤：
1. 将 `Public/Entities/` 中的头文件复制到您的虚幻引擎插件的 `Public/Entities/` 目录
2. 重新生成项目文件（右键 .uproject 文件选择"Generate Visual Studio project files"）
3. 重新编译项目
4. 启动虚幻引擎，错误应该已解决