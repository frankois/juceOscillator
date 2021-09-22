/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JuceOscillatorAudioProcessorEditor::JuceOscillatorAudioProcessorEditor (JuceOscillatorAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Frequency settings
    // freqSlider
    // TODO: set log scale
    mFreqSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mFreqSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    mFreqSlider.setRange(0.0f, 20000.0f, 1.0f);
    mFreqSlider.setValue(220.0f);
    mFreqSlider.setTextValueSuffix (" Hz");
    mFreqSlider.addListener(this);
    addAndMakeVisible(mFreqSlider);
    // freqLabel
    mFreqLabel.setText("Frequency", juce::dontSendNotification);
    mFreqLabel.attachToComponent (&mFreqSlider, false);
    addAndMakeVisible(mFreqLabel);
    
    // Gain settings
    // gainSlider
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    mGainSlider.setRange(-30.0f, 0.0f, 0.01f);
    mGainSlider.setValue(-10.0f);
    mGainSlider.setTextValueSuffix (" dB");
    mGainSlider.addListener(this);
    addAndMakeVisible(mGainSlider);
    // gainLabel
    mGainLabel.setText("Volume", juce::dontSendNotification);
    mGainLabel.attachToComponent (&mGainSlider, false);
    addAndMakeVisible(mGainLabel);
    
    // Global settings
    setSize (400, 300);
}

JuceOscillatorAudioProcessorEditor::~JuceOscillatorAudioProcessorEditor()
{
}

//==============================================================================
void JuceOscillatorAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
//    g.drawFittedText ("Ibekso plugins", getLocalBounds(), juce::Justification::centred, 1);
    g.drawFittedText ("Ibekso Oscillator", 50, getHeight()/2-75, 100, 100, juce::Justification::left, 1);
}

void JuceOscillatorAudioProcessorEditor::resized()
{
    mFreqSlider.setBounds(getWidth()-200, getHeight()/2-75, 100, 150);
    mGainSlider.setBounds(getWidth()-100, getHeight()/2-75, 100, 150);
}

void JuceOscillatorAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &mFreqSlider)
    {
        audioProcessor.mFreq = mFreqSlider.getValue();
    }
    if (slider == &mGainSlider)
    {
        audioProcessor.mGain = mGainSlider.getValue();
    }
}

