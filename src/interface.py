class Exchange:
    # implement this!

    def __init__(self, initialBalance,stocks):
        """Initial Balance is the amount that each account should start with."""
        self.queued = {}
        self.balance = initialBalance
        self.stocks = set(stocks)
        pass

    def add_trade(self, trade):
        """Adds a trade to the exchange (validation required)
        and returns a match if required. It is up to you on how you will
        handle representing trades. """
        try:
            (stock, price, quantity, account) = trade
        except:
            raise ValueError("Trade is not in the correct format")
        
        if stock not in self.stocks:
            raise ValueError("Stock not listed in the exchange")
        
        if not stock in self.queued.keys():
            self.queued[stock] = deque([account])
            return
        else:
            match = self.queued[stock].popleft()
            return (stock, match)
            
