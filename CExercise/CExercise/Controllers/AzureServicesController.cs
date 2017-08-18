using CExercise.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace CExercise.Controllers
{
    public class AzureServicesController : Controller
    {
        // GET: AzureServices
        public ActionResult Index(AzureServices azureService)
        {
            return View(azureService);
        }

        // GET: AzureServices/Details/5
        public ActionResult Details(int id)
        {
            return View();
        }

        // GET: AzureServices/Create
        public ActionResult CalculateService()
        {
            return View();
        }

        // POST: AzureServices/Create
        [HttpPost]
        public ActionResult CalculateService(AzureServices azureService)
        {
            try
            {
                // TODO: Add insert logic here
                if(azureService.NumberOfInstance <= 1)
                {
                    return View(azureService);
                }
                azureService.CostPerHour();
                azureService.CalcYearlyCost();
                return RedirectToAction("Index", azureService);
            }
            catch
            {
                return View();
            }
        }

        // GET: AzureServices/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: AzureServices/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add update logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: AzureServices/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: AzureServices/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
    }
}
