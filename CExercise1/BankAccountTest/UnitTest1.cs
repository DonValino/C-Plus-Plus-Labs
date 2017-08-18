using System;
using CExercise1;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace BankAccountTest
{
    [TestClass]
    public class BankAccountTest
    {

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void WidthdrawWithAmountEqualsZero()
        {
            CurrentAccount c = new CurrentAccount(1, 200);
            c.MakeWidthdraw(0);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void WidthdrawWithAmountLessThanZero()
        {
            CurrentAccount c = new CurrentAccount(1,200);
            c.MakeWidthdraw(-1);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void WidthdrawAmountExceedsBalanceAndOverdraftLimit()
        {
            CurrentAccount c = new CurrentAccount(1, 200);
            c.MakeWidthdraw(250);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void DepositWithAmountLessThanZero()
        {
            CurrentAccount c = new CurrentAccount(1, 200);
            c.MakeDeposit(-1);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void DepositWithAmountEqualsZero()
        {
            CurrentAccount c = new CurrentAccount(1, 200);
            c.MakeDeposit(0);
        }
    }
}
