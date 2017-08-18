using CExercise2.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace CExercise2.Controllers
{
    public class AzureStorageController : Controller
    {
        // GET: AzureStorage
        public ActionResult Index(AzureStorage azureStorage)
        {
            return View(azureStorage);
        }

        // GET: AzureStorage/Details/5
        public ActionResult Details(int id)
        {
            return View();
        }

        // GET: AzureStorage/Create
        public ActionResult CalculateCost()
        {
            return View();
        }

        // POST: AzureStorage/Create
        [HttpPost]
        public ActionResult CalculateCost(AzureStorage azureStorage)
        {
            try
            {
                if(ModelState.IsValid)
                {
                    // No errors added to modelState
                    // Redirect to Index, passing azureStorage 
                    azureStorage.CalculateMonthlyCost();
                    return RedirectToAction("Index", azureStorage);
                }
                
                return View(azureStorage);
            }
            catch
            {
                return View();
            }
        }

        // GET: AzureStorage/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: AzureStorage/Edit/5
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

        // GET: AzureStorage/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: AzureStorage/Delete/5
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
