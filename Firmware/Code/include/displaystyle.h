#ifndef __DISPLAYSTYLE_H__
#define __DISPLAYSTYLE_H__

#include <Arduino.h>
#include <bb_spi_lcd.h>
#include "styleconfig.h"

#define bufferLenght 800
#define buffercounts 32

SPILCD lcd[6];
uint8_t imgBuffer[bufferLenght];

int cs[] = {CS1_PIN, CS2_PIN, CS3_PIN, CS4_PIN, CS5_PIN, CS6_PIN};

void zerostyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = zero_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = zero_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = zero_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = zero_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = zero_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = zero_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = zero_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = zero_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = zero_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


    }
}

void onestyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {


    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = one_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = one_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = one_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = one_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = one_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = one_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;



    
    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = one_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = one_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = one_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    }
}

void twostyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = two_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = two_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = two_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   

    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = two_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = two_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = two_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = two_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    


    
    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = two_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = two_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = two_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    }
}

void threestyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = three_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = three_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = three_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = three_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = three_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = three_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = three_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    


    

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = three_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


   
    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = three_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = three_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    }
}

void fourstyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = four_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = four_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = four_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   
    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = four_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = four_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = four_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = four_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    


    

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = four_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


    
    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = four_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   
    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = four_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    }
}

void fivestyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = five_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = five_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = five_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = five_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = five_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = five_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = five_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   

    

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = five_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


   
    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = five_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = five_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   

    }
}

void sixstyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = six_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = six_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = six_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = six_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = six_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = six_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = six_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   


    

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = six_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


    
    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = six_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = six_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    }
}

void sevenstyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = seven_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = seven_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = seven_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = seven_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = seven_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = seven_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = seven_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    


    

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = seven_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


   

    
    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = seven_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = seven_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    }
}

void eightstyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = eight_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = eight_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = eight_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   

    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = eight_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = eight_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = eight_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = eight_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    


    

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = eight_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


    
    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = eight_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = eight_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   

    }
}

void ninestyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = nine_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = nine_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = nine_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = nine_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = nine_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = nine_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = nine_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;



    

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = nine_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


   

    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = nine_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = nine_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   

    }
}

void colonstyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = colon_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = colon_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = colon_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = colon_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = colon_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = colon_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = colon_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    


    

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = colon_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


   
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = colon_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   
    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = colon_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    }
}

void spacestyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = space_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = space_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = space_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

 
    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = space_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = space_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = space_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

  

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = space_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    


   

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = space_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


   
    
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = space_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

   
    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = space_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    }
}

// void slashstyle(uint8_t Display, uint8_t stylenum)
// {
//     switch (stylenum)
//     {
//     // case SEG14:
//     //     for (int k = 0; k < buffercounts; k++)
//     //     {
//     //         for (int j = 0; j < bufferLenght; j++)
//     //         {
//     //             imgBuffer[j] = slash_14SEG[j + (bufferLenght * k)];
//     //         }
//     //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//     //     }
//     //     break;

//     case BINA:
//         for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = slash_BINA[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;
    
//     case Butterfly:
//     for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = slash_Butterfly[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;

  

//     case Flip:
//     for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = slash_Flip[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;

//     case Flower:
//     for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = slash_Flower[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;

//     case Ink:
//     for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = slash_Ink[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;

 

//     case LixiePurple:
//     for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = slash_LixiePurple[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;

 

    

//     case Nixie:
//     for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = slash_Nixie[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;


 
//     case RGB:
//     for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = slash_RGB[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;

    
    
//     case VFD:
//     for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = slash_VFD[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;

    

//     }
// }



void heartstyle(uint8_t Display, uint8_t stylenum)
{
    switch (stylenum)
    {
    // case SEG14:
    //     for (int k = 0; k < buffercounts; k++)
    //     {
    //         for (int j = 0; j < bufferLenght; j++)
    //         {
    //             imgBuffer[j] = heart_14SEG[j + (bufferLenght * k)];
    //         }
    //         spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
    //     }
    //     break;

    case BINA:
        for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = heart_BINA[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;
    
    case Butterfly:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = heart_Butterfly[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

  

    case Flip:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = heart_Flip[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Flower:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = heart_Flower[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    case Ink:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = heart_Ink[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

 

    case LixiePurple:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = heart_LixiePurple[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

 

    

    case Nixie:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = heart_Nixie[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;


 
    case RGB:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = heart_RGB[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    
    
    case VFD:
    for (int k = 0; k < buffercounts; k++)
        {
            for (int j = 0; j < bufferLenght; j++)
            {
                imgBuffer[j] = heart_VFD[j + (bufferLenght * k)];
            }
            spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        }
        break;

    

    }
}


void lcdDrawNumber(uint8_t Display, uint8_t Number, uint8_t stylenum)
{
    spilcdSetPosition(&lcd[Display], 0, 0, 80, 160, DRAW_TO_LCD);
    switch (Number)
    {
    case 0:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = zero_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        // break;

        zerostyle(Display, stylenum);
        break;

    case 1:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = one_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        onestyle(Display, stylenum);
        break;
    case 2:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = two_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        twostyle(Display, stylenum);
        break;
    case 3:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = three_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        threestyle(Display, stylenum);
        break;
    case 4:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = four_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        fourstyle(Display, stylenum);
        break;
    case 5:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = five_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        fivestyle(Display, stylenum);
        break;
    case 6:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = six_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        sixstyle(Display, stylenum);
        break;
    case 7:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = seven_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        sevenstyle(Display, stylenum);
        break;
    case 8:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = eight_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        eightstyle(Display, stylenum);
        break;
    case 9:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {

        //         imgBuffer[j] = nine_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        ninestyle(Display, stylenum);
        break;
    case 10:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = colon_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        colonstyle(Display, stylenum);
        break;
    case 11:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = space_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        spacestyle(Display, stylenum);
        break;
    case 12:
        // for (int k = 0; k < buffercounts; k++)
        // {
        //     for (int j = 0; j < bufferLenght; j++)
        //     {
        //         imgBuffer[j] = heart_Nixie[j + (bufferLenght * k)];
        //     }
        //     spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
        // }
        heartstyle(Display, stylenum);
        break;
    }
}

// void lcdDrawFlag(uint8_t Display, uint8_t Number)
// {
//     spilcdSetPosition(&lcd[Display], 0, 0, 80, 160, DRAW_TO_LCD);
//     switch (Number)
//     {
//     case 0:
//         for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = mex_Flag[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;
//     case 1:
//         for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = usa_Flag[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;
//     case 2:
//         for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = gbr_Flag[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;
//     case 3:
//         for (int k = 0; k < buffercounts; k++)
//         {
//             for (int j = 0; j < bufferLenght; j++)
//             {
//                 imgBuffer[j] = chn_Flag[j + (bufferLenght * k)];
//             }
//             spilcdWriteDataBlock(&lcd[Display], (uint8_t *)imgBuffer, sizeof(imgBuffer), DRAW_TO_LCD | DRAW_WITH_DMA);
//         }
//         break;
//     }
// }

#endif