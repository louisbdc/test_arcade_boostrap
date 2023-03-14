#include <iostream>
#include <dlfcn.h>

int main()
{
    const char* library_names[] = {"./lib1.so", "./lib2.so"};
    void* libraries[2];

    for (int i = 0; i < 2; i++)
    {
        libraries[i] = dlopen(library_names[i], RTLD_NOW);
        if (!libraries[i])
        {
            std::cerr << "Impossible de charger la bibliothèque " << library_names[i] << ": " << dlerror() << std::endl;
            return 1;
        }

        typedef int (*entry_point_t)();
        entry_point_t entry_point = reinterpret_cast<entry_point_t>(dlsym(libraries[i], "entryPoint"));

        if (!entry_point)
        {
            std::cerr << "Impossible de trouver la fonction entryPoint dans la bibliothèque " << library_names[i] << ": " << dlerror() << std::endl;
            return 1;
        }

        entry_point();

        if (dlclose(libraries[i]) != 0)
        {
            std::cerr << "Impossible de décharger la bibliothèque " << library_names[i] << ": " << dlerror() << std::endl;
            return 1;
        }
    }

    return 0;
}
