/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/prefiks/src/mozilla/trunk/mozilla/modules/libpr0n/public/imgIDecoderObserver1_9.idl
 */

#ifndef __gen_imgIDecoderObserver1_9_h__
#define __gen_imgIDecoderObserver1_9_h__


#ifndef __gen_imgIContainerObserver1_9_h__
#include "imgIContainerObserver1_9.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIRequest; /* forward declaration */

class imgIContainer; /* forward declaration */

class gfxIImageFrame1_9; /* forward declaration */

#include "nsRect.h"

/* starting interface:    imgIDecoderObserver1_9 */
#define IMGIDECODEROBSERVER1_9_IID_STR "876f14ee-f27c-41cd-b6fb-9efda3ebc7b5"

#define IMGIDECODEROBSERVER1_9_IID \
  {0x876f14ee, 0xf27c, 0x41cd, \
    { 0xb6, 0xfb, 0x9e, 0xfd, 0xa3, 0xeb, 0xc7, 0xb5 }}

/**
 * imgIDecoderObserver interface
 *
 * This interface is used both for observing imgIDecoder objects and for
 * observing imgIRequest objects.  In the former case, aRequest is
 * always null.
 * XXXldb The two functions should probably be split.
 *
 * @author Stuart Parmenter <pavlov@netscape.com>
 * @version 0.1
 * @see imagelib2
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgIDecoderObserver1_9 : public imgIContainerObserver1_9 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGIDECODEROBSERVER1_9_IID)

  /**
   * called at the same time that nsIRequestObserver::onStartRequest would be
   * (used only for observers of imgIRequest objects, which are nsIRequests,
   * not imgIDecoder objects)
   *
   * Unlike nsIRequestObserver::onStartRequest, this can be called
   * synchronously.
   */
  /* void onStartRequest (in imgIRequest aRequest); */
  NS_SCRIPTABLE NS_IMETHOD OnStartRequest(imgIRequest *aRequest) = 0;

  /**
   * called as soon as the image begins getting decoded
   */
  /* void onStartDecode (in imgIRequest aRequest); */
  NS_SCRIPTABLE NS_IMETHOD OnStartDecode(imgIRequest *aRequest) = 0;

  /**
   * called once the image has been inited and therefore has a width and height
   */
  /* void onStartContainer (in imgIRequest aRequest, in imgIContainer aContainer); */
  NS_SCRIPTABLE NS_IMETHOD OnStartContainer(imgIRequest *aRequest, imgIContainer *aContainer) = 0;

  /**
   * called when each frame is created
   */
  /* void onStartFrame (in imgIRequest aRequest, in gfxIImageFrame1_9 aFrame); */
  NS_SCRIPTABLE NS_IMETHOD OnStartFrame(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame) = 0;

  /**
   * called when some part of the frame has new data in it
   */
  /* [noscript] void onDataAvailable (in imgIRequest aRequest, in gfxIImageFrame1_9 aFrame, [const] in nsIntRect aRect); */
  NS_IMETHOD OnDataAvailable(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame, const nsIntRect * aRect) = 0;

  /**
   * called when a frame is finished decoding
   */
  /* void onStopFrame (in imgIRequest aRequest, in gfxIImageFrame1_9 aFrame); */
  NS_SCRIPTABLE NS_IMETHOD OnStopFrame(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame) = 0;

  /**
   * probably not needed.  called right before onStopDecode
   */
  /* void onStopContainer (in imgIRequest aRequest, in imgIContainer aContainer); */
  NS_SCRIPTABLE NS_IMETHOD OnStopContainer(imgIRequest *aRequest, imgIContainer *aContainer) = 0;

  /**
   * called when the decoder is dying off
   */
  /* void onStopDecode (in imgIRequest aRequest, in nsresult status, in wstring statusArg); */
  NS_SCRIPTABLE NS_IMETHOD OnStopDecode(imgIRequest *aRequest, nsresult status, const PRUnichar *statusArg) = 0;

  /**
   * called at the same time that nsIRequestObserver::onStopRequest would be
   * (used only for observers of imgIRequest objects, which are nsIRequests,
   * not imgIDecoder objects)
   *
   * Unlike nsIRequestObserver::onStartRequest, this can be called
   * synchronously.
   */
  /* void onStopRequest (in imgIRequest aRequest, in boolean aIsLastPart); */
  NS_SCRIPTABLE NS_IMETHOD OnStopRequest(imgIRequest *aRequest, PRBool aIsLastPart) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIDecoderObserver1_9, IMGIDECODEROBSERVER1_9_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGIDECODEROBSERVER1_9 \
  NS_SCRIPTABLE NS_IMETHOD OnStartRequest(imgIRequest *aRequest); \
  NS_SCRIPTABLE NS_IMETHOD OnStartDecode(imgIRequest *aRequest); \
  NS_SCRIPTABLE NS_IMETHOD OnStartContainer(imgIRequest *aRequest, imgIContainer *aContainer); \
  NS_SCRIPTABLE NS_IMETHOD OnStartFrame(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame); \
  NS_IMETHOD OnDataAvailable(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame, const nsIntRect * aRect); \
  NS_SCRIPTABLE NS_IMETHOD OnStopFrame(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame); \
  NS_SCRIPTABLE NS_IMETHOD OnStopContainer(imgIRequest *aRequest, imgIContainer *aContainer); \
  NS_SCRIPTABLE NS_IMETHOD OnStopDecode(imgIRequest *aRequest, nsresult status, const PRUnichar *statusArg); \
  NS_SCRIPTABLE NS_IMETHOD OnStopRequest(imgIRequest *aRequest, PRBool aIsLastPart); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGIDECODEROBSERVER1_9(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnStartRequest(imgIRequest *aRequest) { return _to OnStartRequest(aRequest); } \
  NS_SCRIPTABLE NS_IMETHOD OnStartDecode(imgIRequest *aRequest) { return _to OnStartDecode(aRequest); } \
  NS_SCRIPTABLE NS_IMETHOD OnStartContainer(imgIRequest *aRequest, imgIContainer *aContainer) { return _to OnStartContainer(aRequest, aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD OnStartFrame(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame) { return _to OnStartFrame(aRequest, aFrame); } \
  NS_IMETHOD OnDataAvailable(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame, const nsIntRect * aRect) { return _to OnDataAvailable(aRequest, aFrame, aRect); } \
  NS_SCRIPTABLE NS_IMETHOD OnStopFrame(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame) { return _to OnStopFrame(aRequest, aFrame); } \
  NS_SCRIPTABLE NS_IMETHOD OnStopContainer(imgIRequest *aRequest, imgIContainer *aContainer) { return _to OnStopContainer(aRequest, aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD OnStopDecode(imgIRequest *aRequest, nsresult status, const PRUnichar *statusArg) { return _to OnStopDecode(aRequest, status, statusArg); } \
  NS_SCRIPTABLE NS_IMETHOD OnStopRequest(imgIRequest *aRequest, PRBool aIsLastPart) { return _to OnStopRequest(aRequest, aIsLastPart); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGIDECODEROBSERVER1_9(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnStartRequest(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStartRequest(aRequest); } \
  NS_SCRIPTABLE NS_IMETHOD OnStartDecode(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStartDecode(aRequest); } \
  NS_SCRIPTABLE NS_IMETHOD OnStartContainer(imgIRequest *aRequest, imgIContainer *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStartContainer(aRequest, aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD OnStartFrame(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStartFrame(aRequest, aFrame); } \
  NS_IMETHOD OnDataAvailable(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame, const nsIntRect * aRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDataAvailable(aRequest, aFrame, aRect); } \
  NS_SCRIPTABLE NS_IMETHOD OnStopFrame(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopFrame(aRequest, aFrame); } \
  NS_SCRIPTABLE NS_IMETHOD OnStopContainer(imgIRequest *aRequest, imgIContainer *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopContainer(aRequest, aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD OnStopDecode(imgIRequest *aRequest, nsresult status, const PRUnichar *statusArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopDecode(aRequest, status, statusArg); } \
  NS_SCRIPTABLE NS_IMETHOD OnStopRequest(imgIRequest *aRequest, PRBool aIsLastPart) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopRequest(aRequest, aIsLastPart); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIDecoderObserver1_9
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGIDECODEROBSERVER1_9

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIDecoderObserver1_9)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onStartRequest (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::OnStartRequest(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStartDecode (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::OnStartDecode(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStartContainer (in imgIRequest aRequest, in imgIContainer aContainer); */
NS_IMETHODIMP _MYCLASS_::OnStartContainer(imgIRequest *aRequest, imgIContainer *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStartFrame (in imgIRequest aRequest, in gfxIImageFrame1_9 aFrame); */
NS_IMETHODIMP _MYCLASS_::OnStartFrame(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void onDataAvailable (in imgIRequest aRequest, in gfxIImageFrame1_9 aFrame, [const] in nsIntRect aRect); */
NS_IMETHODIMP _MYCLASS_::OnDataAvailable(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame, const nsIntRect * aRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStopFrame (in imgIRequest aRequest, in gfxIImageFrame1_9 aFrame); */
NS_IMETHODIMP _MYCLASS_::OnStopFrame(imgIRequest *aRequest, gfxIImageFrame1_9 *aFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStopContainer (in imgIRequest aRequest, in imgIContainer aContainer); */
NS_IMETHODIMP _MYCLASS_::OnStopContainer(imgIRequest *aRequest, imgIContainer *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStopDecode (in imgIRequest aRequest, in nsresult status, in wstring statusArg); */
NS_IMETHODIMP _MYCLASS_::OnStopDecode(imgIRequest *aRequest, nsresult status, const PRUnichar *statusArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStopRequest (in imgIRequest aRequest, in boolean aIsLastPart); */
NS_IMETHODIMP _MYCLASS_::OnStopRequest(imgIRequest *aRequest, PRBool aIsLastPart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIDecoderObserver1_9_h__ */
