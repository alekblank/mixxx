
#include <effects/native/balanceeffect.h>
#include <QtDebug>

#include "effects/native/nativebackend.h"
#include "effects/native/flangereffect.h"
#include "effects/native/bitcrushereffect.h"
#include "effects/native/linkwitzriley8eqeffect.h"
#include "effects/native/bessel8lvmixeqeffect.h"
#include "effects/native/bessel4lvmixeqeffect.h"
#include "effects/native/threebandbiquadeqeffect.h"
#include "effects/native/biquadfullkilleqeffect.h"
#include "effects/native/graphiceqeffect.h"
#include "effects/native/parametriceqeffect.h"
#include "effects/native/filtereffect.h"
#include "effects/native/moogladder4filtereffect.h"
#ifndef __MACAPPSTORE__
#include "effects/native/reverbeffect.h"
#endif
#include "effects/native/echoeffect.h"
#include "effects/native/autopaneffect.h"
#include "effects/native/phasereffect.h"
#include "effects/native/loudnesscontoureffect.h"
#include "effects/native/metronomeeffect.h"

NativeBackend::NativeBackend(QObject* pParent)
        : EffectsBackend(pParent, tr("Native")) {
    // Keep this list in a reasonable order
    // Mixing EQs
    registerEffect<Bessel4LVMixEQEffect>();
    registerEffect<Bessel8LVMixEQEffect>();
    registerEffect<LinkwitzRiley8EQEffect>();
    registerEffect<ThreeBandBiquadEQEffect>();
    registerEffect<BiquadFullKillEQEffect>();
    // Compensations EQs
    registerEffect<GraphicEQEffect>();
    registerEffect<ParametricEQEffect>();
    registerEffect<LoudnessContourEffect>();
    // Fading Effects
    registerEffect<FilterEffect>();
    registerEffect<MoogLadder4FilterEffect>();
    registerEffect<BitCrusherEffect>();
    registerEffect<BalanceEffect>();
    // Fancy effects
    registerEffect<FlangerEffect>();
    registerEffect<EchoEffect>();
    registerEffect<AutoPanEffect>();
#ifndef __MACAPPSTORE__
    registerEffect<ReverbEffect>();
#endif
    registerEffect<PhaserEffect>();
    registerEffect<MetronomeEffect>();
}

NativeBackend::~NativeBackend() {
    //qDebug() << debugString() << "destroyed";
}
