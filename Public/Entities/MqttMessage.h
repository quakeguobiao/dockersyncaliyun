// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MqttMessage.generated.h"

/**
 * MQTT Message structure
 */
USTRUCT(BlueprintType)
struct MQTTUTILITIES_API FMqttMessage
{
	GENERATED_BODY()

	/** The topic of the message */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	FString Topic;

	/** The payload of the message */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	FString Payload;

	/** Whether the message should be retained by the broker */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	bool Retain = false;

	/** Quality of Service level (0, 1, or 2) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	int32 Qos = 0;

	FMqttMessage()
		: Topic(TEXT(""))
		, Payload(TEXT(""))
		, Retain(false)
		, Qos(0)
	{
	}
};
