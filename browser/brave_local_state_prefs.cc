/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/brave_local_state_prefs.h"

#include "brave/browser/brave_stats_updater.h"
#include "brave/components/brave_referrals/brave_referrals_service.h"

namespace brave {

void RegisterLocalStatePrefs(PrefRegistrySimple* registry) {
  RegisterPrefsForBraveStatsUpdater(registry);
  RegisterPrefsForBraveReferralsService(registry);
}

}  // namespace brave
