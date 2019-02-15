#[macro_use]
extern crate criterion;
// extern crate is no longer a best practice, I was just reading out of date docs
// see https://doc.rust-lang.org/nightly/edition-guide/rust-2018/module-system/path-clarity.html

use criterion::Criterion;
use criterion::ParameterizedBenchmark;
use criterion::Throughput;
use nativelib::hamming_distance;
use nativelib::multiply;

fn multiply_benchmark(c: &mut Criterion) {
    let params = vec![
        (23278, 25058),
        (24552, 44005),
        (31159, 27339),
        (42587, 19588),
        (44273, 16819),
    ];

    c.bench(
        "multiply",
        ParameterizedBenchmark::new(
            "multiply",
            |b, args| b.iter(|| multiply(args.0, args.1)),
            params,
        )
        .throughput(|_| Throughput::Elements(1)),
    );
}

fn hamming_distance_benchmark(c: &mut Criterion) {
    let params = vec![
        (2241772153, 3635078742),
        (224845246, 2076596368),
        (586774217, 2068741568),
        (596452998, 3747699255),
        (907505648, 984890663),
    ];

    c.bench(
        "hamming_distance",
        ParameterizedBenchmark::new(
            "hamming_distance",
            |b, args| b.iter(|| hamming_distance(args.0, args.1)),
            params,
        )
        .throughput(|_| Throughput::Elements(1)),
    );
}

criterion_group!(benches, multiply_benchmark, hamming_distance_benchmark);
criterion_main!(benches);
