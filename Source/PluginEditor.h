/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class JuceOscillatorAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                            public juce::Slider::Listener
{
public:
    JuceOscillatorAudioProcessorEditor (JuceOscillatorAudioProcessor&);
    ~JuceOscillatorAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;

private:
    juce::Slider mFreqSlider;
    juce::Label mFreqLabel;
    juce::Slider mGainSlider;
    juce::Label mGainLabel;
    
    JuceOscillatorAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceOscillatorAudioProcessorEditor)
};
