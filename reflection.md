# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection

### Describe the effect each of the P, I, D components had in your implementation.

First, note that I implemented a PID controller for steering only. Qualitatively speaking, the effects of tweaking the proportional gain (P), integral gain (I), and differential gain (D) are as follows.

_P:_

Setting too high of a value for _P_ tends to create osciallations in the driving trajectory. At worst, this caused the vehicle to swerve off the road. At best, this causes a very uncomfortable ride.

Setting too low of a value for _P_ results on the vehicle not turning enough in tight corners. This might cause the vehicle to run off track in a tight corner.

_I:_

When I set _I_ to 0, honestly I didn't notice much difference in behavior. The purpose of _I_ is to compensate for an inherent steering bias in the vehicle, so this leads me to conclude that the vehicle has very little or no steering bias.

When I set _I_ to a significantly high value, I noticed the vehicle swerves a lot, since the _I_ term causes the vehicle to overcompensate for the CTE (over time).

_D:_

_D_ tends to be the "counter-weight" to _P_.

Setting too high of a value for _D_ causes the vehicle to turn too slowly. This would cause an issue in tight corners, where the vehicle may drive off the road.

Setting too low of a value for _D_ means the effects of _P_ will be unchecked, which tends to result in the vehicle osciallating about its intended path.

### Describe how the final hyperparameters were chosen.

The final hyperparameters were manually chosen. Based on the effects of P, I, D described above, I would tweak P/I/D depending on how the vehicle behaved in the simulation.

For example, if I observed the vehicle was oscillating too harshly about its intended path, I would either decrease P, increase D, or both. On the other hand, if I observed the vehicle going too straight through tight corners, I would do the opposite (increase P, decrease D, or both).

As for the hyperparameter _I_, I first noticed that setting _I_ to non-zero values was causing the vehicle to oscillate too much in the beginning, sometimes driving off the road at the very start. Then I set _I_ to 0 and the vehicle was able to make it around the track. In the end, I settled for a relative small value of _I_.

### A note about throttle

I did not use a separate PID controller to control throttle, but that would be a very good future enhancement to this project. For throttle, I set its value as a simple linear function of the steering value.
