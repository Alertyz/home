int swap = -1;
if (swap != 0)
{
    do
    {
        swap = 0;
        for (int b = 0; b < z; b++)
        {
            int a = b + 1;
            if (a > candidate_count)
            {
                a = candidate_count;
            }
            if (candidates[b].votes > candidates[a].votes)
            {
                int copy1 = candidates[b].votes;
                int copy2 = candidates[a].votes;
                candidates[b].votes == copy2;
                candidates[a].votes == copy1;
                swap++
            }
        }
    }
    while (swap != 0)
}
