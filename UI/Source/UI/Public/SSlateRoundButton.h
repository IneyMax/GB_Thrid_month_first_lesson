// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

enum class ERadioChoise : uint8
{
	Switch0,
	Switch1,
	Switch2
};

class UI_API SSlateRoundButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlateRoundButton)
	{}
	SLATE_END_ARGS()
	
	void Construct(const FArguments& InArgs);
};
