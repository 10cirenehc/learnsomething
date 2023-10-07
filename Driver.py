import cppimport.import_hook
import PricingUtil


if __name__ == "__main__":
    prevPrice = 10.34
    interest = 1.5
    oleoConstant = 0.8
    print(f"Previous price: {prevPrice}, interest: {interest}, Oleo Constant: {oleoConstant}")
    priceUtil = PricingUtil.PricingUtil()
    val = priceUtil.calcVal(prevPrice, interest, oleoConstant)
    print(f"Theoretical value is: {val}")
    print("Nice work on creating the util! Make sure to check the unit tests!")
