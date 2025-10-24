// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MqttClientConfig.generated.h"

/**
 * MQTT Client Configuration structure
 */
USTRUCT(BlueprintType)
struct MQTTUTILITIES_API FMqttClientConfig
{
	GENERATED_BODY()

	/** The hostname or IP address of the MQTT broker */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	FString Host;

	/** The port number of the MQTT broker */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	int32 Port = 1883;

	/** The client ID to use when connecting */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	FString ClientId;

	/** Username for authentication (optional) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	FString Username;

	/** Password for authentication (optional) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	FString Password;

	/** Keep alive interval in seconds */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	int32 KeepAliveInterval = 60;

	/** Clean session flag */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MQTT")
	bool CleanSession = true;

	FMqttClientConfig()
		: Host(TEXT("localhost"))
		, Port(1883)
		, ClientId(TEXT(""))
		, Username(TEXT(""))
		, Password(TEXT(""))
		, KeepAliveInterval(60)
		, CleanSession(true)
	{
	}
};
