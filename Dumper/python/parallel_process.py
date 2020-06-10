import multiprocessing
import datetime, time

def parallel_process(proc_function, argu_list):

    process_list = []

    for argu_element in argu_list:

        p = multiprocessing.Process(target = proc_function, args = tuple(argu_element))
        process_list.append(p)


    njobs = len(process_list)
    print 'Need %s jobs' % njobs

    iproc = 0
    pend_jobs = njobs
    tmp_index = -1

    init_time = datetime.datetime.now()

    while len(multiprocessing.active_children()) != 0 or pend_jobs != 0 :

        if len(multiprocessing.active_children()) is not tmp_index:
            run_jobs = len(multiprocessing.active_children())
            finish_jobs = njobs - pend_jobs - run_jobs
            delta_time = (datetime.datetime.now() - init_time).total_seconds()

            minutes = int(delta_time / 60)
            seconds = delta_time - minutes * 60

            print 'Pending : %d, Running : %d, Finished : %d, [ time : %dm %ds ]' % ( pend_jobs,
                                                                               run_jobs,
                                                                               finish_jobs,
                                                                               minutes,
                                                                               seconds )
            tmp_index = run_jobs

        if len(multiprocessing.active_children()) < 24 and iproc < njobs:
            submit_jobs = min( njobs - iproc, 24 - len(multiprocessing.active_children()) )
            for dummy_index in range(submit_jobs):
                process_list[iproc].start()
                iproc += 1
                pend_jobs -= 1

        time.sleep(1)

    print 'Pending : 0, Running : 0, Finished : %d, [ finished ]' % njobs
