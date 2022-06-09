#include "RadioButtons.h"

void URadioButtons::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	//MyRadioButton.ToSharedRef()->ChangeNumberOfOptions(NumberOfOptions);
	MyRadioButton.Reset();
}

TSharedRef<SWidget> URadioButtons::RebuildWidget()
{
	MyRadioButton = SNew(SSlateRadioButtons)
	.OnRadioButtonChanged(BIND_UOBJECT_DELEGATE(FOnRadioButtonChanged, HandleRadioButtonStateChanged));
	
	if (MyRadioButton.IsValid())
	{
		MyRadioButton.ToSharedRef()->ChangeNumberOfOptions(NumberOfOptions);
		NumberOfOptions = MyRadioButton.ToSharedRef()->GetNumberOfOptions();
	}
	else
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Ref not found!!!!"));
	}

	return  MyRadioButton.ToSharedRef();
}

void URadioButtons::HandleRadioButtonStateChanged(int32 NewRadioChoise)
{
	if(OnRadioButtonChanged.IsBound())
	{
		OnRadioButtonChanged.Broadcast(NewRadioChoise);
	}
}

