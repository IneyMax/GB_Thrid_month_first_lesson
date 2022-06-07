// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlateRoundButton.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlateRoundButton::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		[
			SNew(SCheckBox)
				[
					SNew(STextBlock).Text(FText::FromString(" Switch 1 "))
				]
		]
		+ SVerticalBox::Slot()
		[
			SNew(SCheckBox)
			[
				SNew(STextBlock).Text(FText::FromString(" Switch 2 "))
			]
		]
		+ SVerticalBox::Slot()
		[
			SNew(SCheckBox)
			[
				SNew(STextBlock).Text(FText::FromString(" Switch 3 "))
			]
		]
		// Populate the widget
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
