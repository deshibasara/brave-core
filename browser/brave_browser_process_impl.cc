// Copyright (c) 2017 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brave/browser/brave_browser_process_impl.h"

#include "brave/components/brave_shields/browser/ad_block_service.h"
#include "brave/components/brave_shields/browser/https_everywhere_service.h"
#include "brave/components/brave_shields/browser/tracking_protection_service.h"

BraveBrowserProcessImpl* g_brave_browser_process = nullptr;


BraveBrowserProcessImpl::~BraveBrowserProcessImpl() {
}

BraveBrowserProcessImpl::BraveBrowserProcessImpl(
    base::SequencedTaskRunner* local_state_task_runner,
    const base::CommandLine& command_line)
    : BrowserProcessImpl(local_state_task_runner, command_line) {
  g_browser_process = this;
  g_brave_browser_process = this;
}

brave_shields::BaseBraveShieldsService*
BraveBrowserProcessImpl::ad_block_service() {
  if (ad_block_service_)
    return ad_block_service_.get();

  ad_block_service_ = brave_shields::AdBlockServiceFactory();
  return ad_block_service_.get();
}

brave_shields::BaseBraveShieldsService*
BraveBrowserProcessImpl::tracking_protection_service() {
  if (tracking_protection_service_)
    return tracking_protection_service_.get();

  tracking_protection_service_ =
    brave_shields::TrackingProtectionServiceFactory();
  return tracking_protection_service_.get();
}

brave_shields::HTTPSEverywhereService*
BraveBrowserProcessImpl::https_everywhere_service() {
  if (https_everywhere_service_)
    return https_everywhere_service_.get();

  https_everywhere_service_ =
    brave_shields::HTTPSEverywhereServiceFactory();
  return https_everywhere_service_.get();
}