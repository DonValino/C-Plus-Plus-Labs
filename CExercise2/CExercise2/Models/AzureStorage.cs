using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace CExercise2.Models
{
    public class AzureStorage
    {

        // Cost Per month
        [Display(Name ="Cost Per Month")]
        public double CostPerMonth { get; set; }

        // Number Of Gigs
        [Required]
        [Display(Name ="Number Of Gigs")]
        [Range(1,3000)]
        public int NumberOfGig { get; set; }

        // Type of Redundancy
        [Required]
        [Display(Name = "Redundancy Type")]
        public TypeOfRedundancy RedundancyType { get; set; }

        // Calculate Monthly Cost
        public void CalculateMonthlyCost()
        {
            if(RedundancyType == TypeOfRedundancy.Geographically_redundant)
            {
                if(NumberOfGig <= 1000)
                {
                    CostPerMonth = NumberOfGig * 0.125;
                }else
                {
                    CostPerMonth = ((NumberOfGig - 1000) * 0.11) + (1000 * 0.125);
                }
            }else
            {
                if (NumberOfGig <= 1000)
                {
                    CostPerMonth = NumberOfGig * 0.093;
                }
                else
                {
                    CostPerMonth = ((NumberOfGig - 1000) * 0.083) + (1000 * 0.093);
                }
            }
        }

        // Type of redundancy type enum
        public enum TypeOfRedundancy
        {
            Geographically_redundant, Locally_redundant
        }
    }
}