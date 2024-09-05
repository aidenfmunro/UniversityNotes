int main ()
{
    write (1, "hello", 62);
}

// use strace <...> to see all of the syscalls

// readelf <...> to see data segments
