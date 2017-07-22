---
title: "Reflections"
output: html_document
---

## Reflections of CarND PID Controller Project

### PID components

- P component let the controller react fast by increasing the value, but it also cause oscilation.

- D component is used to reduce oscilation, but if it is overtuned, it causes also oscilation.

- I component is used to reach stationary accuracy, the parameter for I component should not be a great value since all CTE are added up and the component increases. In our case, the controller output (steering) is limited and if we have large error, e.g. of the track, the I component will have the effect that our controller stucks at limit.


### Manual tuning of the parameters
I've started at zero and firstly tuned P-parameter until the car steer quick enough. Since the car oscilate and go off the track, I've added D-parameter to counter-steer the oscilation. By tweaking these two parameters, I've got good visual result in the simulator at P = 0.3 and D = 11.0.

Since the path of the a car on the track is dynamic, stationary accuracy of the I component is irrelvant for the task of steering, therefore the I-parameter can be set to 0.0. 


### Low pass filter
I've also added a low pass filter (PT1 filter) to simulate the latency of steering system and tire. 

### PID-controller for Throttle
I used a PID-controller to keep speed at 60.0 mph. 


