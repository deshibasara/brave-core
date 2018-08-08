/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

import { action } from 'typesafe-actions'

// Constant
import { types } from '../constants/rewards_types'

export const createWallet = () => action(types.CREATE_WALLET)

export const onWalletCreated = () => action(types.WALLET_CREATED)

export const onWalletCreateFailed = () => action(types.WALLET_CREATE_FAILED)

export const onSettingSave = (key: string, value: any) => action(types.ON_SETTING_SAVE, {
  key,
  value
})

export const getWalletProperties = () => action(types.GET_WALLET_PROPERTIES)

export const onWalletProperties = (properties: Rewards.WalletProperties) => action(types.ON_WALLET_PROPERTIES, {
  properties
})

export const getPromotion = () => action(types.GET_PROMOTION)

export const onPromotion = (properties: Rewards.Promotion) => action(types.ON_PROMOTION, {
  properties
})

export const getPromotionCaptcha = () => action(types.GET_PROMOTION_CAPTCHA)

export const onPromotionCaptcha = (properties: Rewards.Promotion) => action(types.ON_PROMOTION_CAPTCHA, {
  properties
})
