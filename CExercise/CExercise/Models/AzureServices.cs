using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace CExercise.Models
{
    public class AzureServices
    {
        // Yearly Cost Variable
        [Display(Name = "Yearly Cost €")]
        public double YearlyCost
        {
            get;
            set;
        }

        //Today's date
        public static DateTime Today { get; }

        // Number of instance variable
        [Required]
        [Range(2, 100)]
        [Display(Name ="Number Of Instance")]
        public int NumberOfInstance{ get; set; }

        // Hourly Cost
        [Display(Name = "Hourly Cost €")]
        public double HourlyCost { get; set; }

        // Cost Per hour
        public void CostPerHour()
        {
            if (selectedInstancePrice == InstancePrice.Very_Small)
            {
                HourlyCost = (0.02 * NumberOfInstance);
            }
            else if (selectedInstancePrice == InstancePrice.Small)
            {
                HourlyCost = (0.08 * NumberOfInstance);
            }
            else if (selectedInstancePrice == InstancePrice.Medium)
            {
                HourlyCost = (0.16 * NumberOfInstance);
            }
            else if (selectedInstancePrice == InstancePrice.Large)
            {
                HourlyCost = (0.32 * NumberOfInstance);
            }
            else if (selectedInstancePrice == InstancePrice.Very_Large)
            {
                HourlyCost = (0.64 * NumberOfInstance);
            }
            else if (selectedInstancePrice == InstancePrice.A6)
            {
                HourlyCost = (0.90 * NumberOfInstance);
            }
            else
            {
                HourlyCost = (1.80 * NumberOfInstance);
            }
        }

        // Calculating the yearly cost
        public double CalcYearlyCost()
        {
            if(selectedInstancePrice == InstancePrice.Very_Small)
            {
                if(DateTime.IsLeapYear(Today.Year))
                {
                    YearlyCost = NumberOfInstance * ((0.02 * 24) * 366);
                }else
                {
                    YearlyCost = NumberOfInstance * ((0.02 * 24) * 365);
                }
                
            }else if(selectedInstancePrice == InstancePrice.Small)
            {
                if (DateTime.IsLeapYear(Today.Year))
                {
                    YearlyCost = NumberOfInstance * ((0.08 * 24) * 366);
                }
                else
                {
                    YearlyCost = NumberOfInstance * ((0.08 * 24) * 365);
                }
            }
            else if(selectedInstancePrice == InstancePrice.Medium)
            {
                if (DateTime.IsLeapYear(Today.Year))
                {
                    YearlyCost = NumberOfInstance * ((0.16 * 24) * 366);
                }
                else
                {
                    YearlyCost = NumberOfInstance * ((0.16 * 24) * 365);
                }
            }
            else if(selectedInstancePrice == InstancePrice.Large)
            {
                if (DateTime.IsLeapYear(Today.Year))
                {
                    YearlyCost = NumberOfInstance * ((0.32 * 24) * 366);
                }
                else
                {
                    YearlyCost = NumberOfInstance * ((0.32 * 24) * 365);
                }
            } else if(selectedInstancePrice == InstancePrice.Very_Large)
            {
                if (DateTime.IsLeapYear(Today.Year))
                {
                    YearlyCost = NumberOfInstance * ((0.64 * 24) * 366);
                }
                else
                {
                    YearlyCost = NumberOfInstance * ((0.64 * 24) * 365);
                }
            }
            else if(selectedInstancePrice == InstancePrice.A6)
            {
                if (DateTime.IsLeapYear(Today.Year))
                {
                    YearlyCost = NumberOfInstance * ((0.90 * 24) * 366);
                }
                else
                {
                    YearlyCost = NumberOfInstance * ((0.90 * 24) * 365);
                }
            }
            else
            {
                if (DateTime.IsLeapYear(Today.Year))
                {
                    YearlyCost = NumberOfInstance * ((1.80 * 24) * 366);
                }
                else
                {
                    YearlyCost = NumberOfInstance * ((1.80 * 24) * 365);
                }
            }
            return YearlyCost;
        }

        // Price of an instance based on size
        [Required]
        [Display(Name = "Instance Size")]
        public InstancePrice selectedInstancePrice { get; set; }


        //Enum to represent the different instance price for size
        public enum InstancePrice
        {
            Very_Small, Small, Medium, Large, Very_Large, A6, A7
        }
    }
}