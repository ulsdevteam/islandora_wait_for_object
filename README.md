# islandora_wait_for_object

## Purpose
To assist preventing a bottleneck during ingest.

This will try to access the object's datastream specified by the $dsid value (usually OBJ, but could be other datastreams).
1. If that datastream is an object, return TRUE
2. Wait 1 second
3. If the datastream is an object now, return TRUE
4. if the total wait time is less than variable_get('islandora_wait_for_object_max_seconds', 30), return to step 2
