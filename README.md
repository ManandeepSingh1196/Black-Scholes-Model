# Black-Scholes Option Pricing Model

A C++ implementation of the Black-Scholes model for pricing European options.

## Overview

The Black-Scholes model is a mathematical framework for determining the theoretical price of options. This implementation provides:

- European call and put option pricing
- Automatic calculation of d1 and d2 parameters
- Normal cumulative distribution function approximation
- Complete getter/setter interface

## Parameters

- **S₀** (optionPrice): Current price of underlying asset
- **K** (strikePrice): Strike price of the option
- **T** (timeToMaturity): Time to expiration in years
- **r** (riskFreeRate): Risk-free interest rate
- **σ** (volatility): Volatility of the underlying asset

## Formulas

**Call Option:**
```
C = S₀ × N(d₁) - K × e^(-rT) × N(d₂)
```

**Put Option:**
```
P = K × e^(-rT) × N(-d₂) - S₀ × N(-d₁)
```

**Where:**
```
d₁ = [ln(S₀/K) + (r + σ²/2)T] / (σ√T)
d₂ = d₁ - σ√T
```

## License

MIT License