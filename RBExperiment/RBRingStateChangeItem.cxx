
#include <stdio.h>

#include <TTree.h>
#include <TFile.h>
#include <TEventList.h>

// #ifndef __RBRingStateChangeItem_H
// #define __RBRingStateChangeItem_H
#include "RBRingStateChangeItem.h"
  //#endif


ClassImp(RBRingStateChangeItem);

////////////////////////////////////////////////////////////////////////////////
/* BEGIN_HTML

END_HTML */
////////////////////////////////////////////////////////////////////////////////

//______________________________________________________________________________
RBRingStateChangeItem::RBRingStateChangeItem(ULong64_t eventTimestamp, UInt_t sourceId, UInt_t barrierType,
                                             std::string reason, UInt_t runNumber, UInt_t timeOffset,
                                             time_t timestamp, std::string title)
{
  SetType(reason);
  SetBodyHeader(eventTimestamp, sourceId, barrierType);
  fRunNumber  = runNumber;
  fTimeOffset = timeOffset;
  fTimestamp  = timestamp;
  fRunTitle   = title;
}

//______________________________________________________________________________
void RBRingStateChangeItem::Clear(Option_t *)
{
  // -- Clear the data members
  //

}


//______________________________________________________________________________
void RBRingStateChangeItem::InitClass()
{
  // -- Initialize the class to its default settings.
  //

  Clear();
}


//______________________________________________________________________________
void RBRingStateChangeItem::InitTree(TTree *tree)
{
  // -- Set the branch pointers.
  //

  fChain = tree;
  fCurrent = -1;


}
