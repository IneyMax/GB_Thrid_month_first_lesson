// Fill out your copyright notice in the Description page of Project Settings.

#include "SSlateRadioButtons.h"
#include "SlateOptMacros.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlateRadioButtons::Construct(const FArguments& InArgs)
{
	SOnRadioButtonChanged = InArgs._OnRadioButtonChanged;
	SCurrentChoice.Set( InArgs._CurrentChoice );
	SNumberOfOptions.Set( InArgs._NumberOfOptions );
	
	ChildSlot
	[
		SAssignNew(SMyDynamicVerticalBox , SVerticalBox)
	];
	
	for (int i = 0; i < SNumberOfOptions.Get(); ++i)
	{
		SMyDynamicVerticalBox->AddSlot()
		[
			SCreateRadioButton("Options ", i)
		];
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION


ECheckBoxState SSlateRadioButtons::SIsRadioButtonChecked(int32 RadioButtonID)
{
	return (SCurrentChoice.Get() == RadioButtonID) ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}


void SSlateRadioButtons::SHandleRadioButtonStateChanged(ECheckBoxState NewRadioState, int32 RadioButtonID)
{
	if (NewRadioState == ECheckBoxState::Checked)
	{
		SCurrentChoice = RadioButtonID;
		SOnRadioButtonChanged.ExecuteIfBound(RadioButtonID); // For UMG
	}
}

TSharedRef<SWidget> SSlateRadioButtons::SCreateRadioButton(const FString& RadioText, int32 RadioButtonChoice)
{
	return SNew(SCheckBox)
	.IsChecked(MakeAttributeRaw(this, &SSlateRadioButtons::SIsRadioButtonChecked, RadioButtonChoice))
	.OnCheckStateChanged(this, &SSlateRadioButtons::SHandleRadioButtonStateChanged, RadioButtonChoice)
	[
		SNew(STextBlock)
		.Text(FText::FromString(RadioText))
	];
}

