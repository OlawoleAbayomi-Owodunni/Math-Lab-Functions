/*==============================================================================
Do not edit any code in this file!!!


██████   ██████      ███    ██  ██████  ████████     ███████ ██████  ██ ████████
██   ██ ██    ██     ████   ██ ██    ██    ██        ██      ██   ██ ██    ██
██   ██ ██    ██     ██ ██  ██ ██    ██    ██        █████   ██   ██ ██    ██
██   ██ ██    ██     ██  ██ ██ ██    ██    ██        ██      ██   ██ ██    ██
██████   ██████      ██   ████  ██████     ██        ███████ ██████  ██    ██


████████ ██   ██ ██ ███████     ███████ ██ ██      ███████ ██
   ██    ██   ██ ██ ██          ██      ██ ██      ██      ██
   ██    ███████ ██ ███████     █████   ██ ██      █████   ██
   ██    ██   ██ ██      ██     ██      ██ ██      ██
   ██    ██   ██ ██ ███████     ██      ██ ███████ ███████ ██

==============================================================================*/
#pragma once
#pragma comment(lib,"TargetFunctions.lib")

float sqr(float n);
float cub(float n);


float moveHorizLineTarget(float t);

float changeSlopeTarget(float t);

float changeSlopeAndMoveTarget(float t); 

float makeParabolicTarget(float t);

float moveParabolsLeftTarget(float t);

float moveParabolaUpTarget(float t);

float moveCubicLeftTarget(float t);

float moveCubicDownTarget(float t);

float invertParabolaTarget(float t);

float widenParabolaTarget(float t);

float widenAndMoveParabolaTarget(float t);

float easeInTarget(float t);

float easeInUpsideDownTarget(float t);

float easeInFlipVertTarget(float t);

float easeOutTarget(float t);

float easeInThruCentreTarget(float t);

float easeOutThruCentreTarget(float t);

float easeInOutTarget(float t);

float easeInCubicTarget(float t);

float easeInOutCubicTarget(float t);

float easeInCubicThruCenterTarget(float t);
