// Fill out your copyright notice in the Description page of Project Settings.

// Сложить все кнопки в массив для хранения

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

DECLARE_DELEGATE_OneParam( FOnRadioButtonChanged, int32 )

class UI_API SSlateRadioButtons : public SCompoundWidget
{
	
public:
	SLATE_BEGIN_ARGS( SSlateRadioButtons ):
		_CurrentChoice (0)
		, _NumberOfOptions (0)
		{}
	
	SLATE_ARGUMENT( int32, CurrentChoice )

	SLATE_ARGUMENT( int32, NumberOfOptions )
	
	SLATE_EVENT( FOnRadioButtonChanged, OnRadioButtonChanged )
	
	SLATE_END_ARGS()
	
	void Construct(const FArguments& InArgs);
	
protected:

	TAttribute<int32> SCurrentChoice;
	TAttribute<int32> SNumberOfOptions;
	
	FOnRadioButtonChanged SOnRadioButtonChanged;
	TSharedPtr<SVerticalBox> SMyDynamicVerticalBox;
	
protected:
	ECheckBoxState SIsRadioButtonChecked (int32 RadioButtonID);
	void SHandleRadioButtonStateChanged(ECheckBoxState NewRadioState, int32 RadioButtonID);
	TSharedRef<SWidget> SCreateRadioButton(const FString& RadioText, int32 RadioButtonChoice);
};
