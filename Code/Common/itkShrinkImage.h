/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkShrinkImage.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
/**
 * ShrinkImage reduces the size of an image by an integer factor.
 */
#ifndef __itkShrinkImage_h
#define __itkShrinkImage_h

#include "itkFilterImageToImage.h"

namespace itk
{

template <class TInputImage, class TOutputImage>
class ITK_EXPORT ShrinkImage:
    public FilterImageToImage<TInputImage,TOutputImage>
{
public:
  /** 
   * Smart pointer typedef support.
   */
  typedef ShrinkImage         Self;
  typedef SmartPointer<Self>  Pointer;

  /**
   * Method for creation through the object factory.
   */
  itkNewMacro(Self);  

  /** 
   * Run-time type information (and related methods).
   */
  itkTypeMacro(ShrinkImage, FilterImageToImage);

  /** 
   * Set the shrink factor. The default value is 1.
   */
  itkSetMacro(ShrinkFactor,unsigned int);
  
  /** 
   * Get the shrink factor.
   */
  itkGetMacro(ShrinkFactor,unsigned int);
                 
protected:
  ShrinkImage();
  ~ShrinkImage() {};
  ShrinkImage(const Self&) {}
  void operator=(const Self&) {}
  void PrintSelf(std::ostream& os, Indent indent);
  
  void Execute();

private:
  unsigned int m_ShrinkFactor;
};

  
} // namespace itk
  
#ifndef ITK_MANUAL_INSTANTIATION
#include "itkShrinkImage.txx"
#endif
  
#endif
