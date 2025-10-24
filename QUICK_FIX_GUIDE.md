# Quick Fix Guide (快速修复指南)

## English

### What was fixed?
Three Unreal Engine property initialization errors in MQTT utility structures:
- ✅ `FMqttMessage::Retain` - Now initialized to `false`
- ✅ `FMqttMessage::Qos` - Now initialized to `0`
- ✅ `FMqttClientConfig::Port` - Now initialized to `1883`

### How to apply?
1. Copy header files to your Unreal project
2. Delete `Intermediate/` and `Binaries/` folders
3. Right-click `.uproject` → "Generate Visual Studio project files"
4. Rebuild in Visual Studio
5. Launch Unreal Engine ✨

### Do I need to rebuild? (YES!)
**是的，需要重新生成二进制文件！** After changing header files with UPROPERTY, you MUST rebuild.

---

## 中文

### 修复了什么？
三个虚幻引擎 MQTT 工具结构的属性初始化错误：
- ✅ `FMqttMessage::Retain` - 现已初始化为 `false`
- ✅ `FMqttMessage::Qos` - 现已初始化为 `0`
- ✅ `FMqttClientConfig::Port` - 现已初始化为 `1883`

### 如何应用？
1. 将头文件复制到您的虚幻项目中
2. 删除 `Intermediate/` 和 `Binaries/` 文件夹
3. 右键点击 `.uproject` → 选择"Generate Visual Studio project files"
4. 在 Visual Studio 中重新编译
5. 启动虚幻引擎 ✨

### 需要重新编译吗？（需要！）
**是的！** 修改带有 UPROPERTY 的头文件后，**必须**重新编译二进制文件。

---

## Files Changed

### MqttMessage.h
```cpp
// Before (错误)
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
bool Retain;  // ❌ Not initialized

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
int32 Qos;    // ❌ Not initialized

// After (正确)
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
bool Retain = false;  // ✅ Initialized

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
int32 Qos = 0;        // ✅ Initialized
```

### MqttClientConfig.h
```cpp
// Before (错误)
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
int32 Port;  // ❌ Not initialized

// After (正确)
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
int32 Port = 1883;  // ✅ Initialized (default MQTT port)
```

## Why This Fix Works

Unreal Engine's reflection system requires all UPROPERTY members in USTRUCT to have default values. The fix provides:

1. **Default member initializers** (modern C++ style)
2. **Constructor initialization** (traditional style)
3. **Proper defaults** for MQTT protocol (Port 1883, QoS 0, etc.)

虚幻引擎的反射系统要求 USTRUCT 中的所有 UPROPERTY 成员都有默认值。此修复提供了：

1. **默认成员初始化器**（现代 C++ 风格）
2. **构造函数初始化**（传统风格）
3. **MQTT 协议的正确默认值**（端口 1883、QoS 0 等）
