using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(CExercise.Startup))]
namespace CExercise
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
